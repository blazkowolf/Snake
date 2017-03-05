#pragma once

#include <string>
#include <functional>
#include <vector>

class Event {

	private:
		/* Force instantiation from within this class */
		Event ();
		static std::vector<std::pair<std::string, std::function<void()>>> behaviors;

	public:
		inline static void StoreBehavior ( const std::string& funcName, const std::function<void()>& function ) {
			behaviors.push_back( std::make_pair( funcName, function ) );
		}

		inline static void Call ( const std::string& funcName ) {
			for ( unsigned int i = 0; i < behaviors.size(); i++ ) {
				if ( funcName == behaviors[i].first ) {
					behaviors[i].second();
					break;
				}
			}
		}

};