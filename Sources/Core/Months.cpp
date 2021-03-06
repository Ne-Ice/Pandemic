#include <Headers/Core/Months.h>
#include <Headers/Logging/Logger.h>
#include <string>

namespace pan {
	UShort Months::getNumberOfDaysInMonth(MonthsEnum& month) const {
		return getMonthInfo(month).numberOfDays;
	}

	Months::Months() {
		// TODO add days_in_year == sum(days_in_all_months) check
		MonthInfo info;
		info.monthName = "Winter - 1";
		info.numberOfDays = 20;
		months.insert(std::make_pair(WINTER_1, info));

		info.monthName = "Winter - 2";
		info.numberOfDays = 23;
		months.insert(std::make_pair(WINTER_2, info));

		info.monthName = "Winter - 3";
		info.numberOfDays = 24;
		months.insert(std::make_pair(WINTER_3, info));

		info.monthName = "Spring - 1";
		info.numberOfDays = 24;
		months.insert(std::make_pair(SPRING_1, info));

		info.monthName = "Spring - 2";
		info.numberOfDays = 21;
		months.insert(std::make_pair(SPRING_2, info));

		info.monthName = "Summer - 1";
		info.numberOfDays = 28;
		months.insert(std::make_pair(SUMMER_1, info));

		info.monthName = "Autumn - 1";
		info.numberOfDays = 20;
		months.insert(std::make_pair(AUTUMN_1, info));
	}

	Months::~Months() {
	}

	Months::MonthInfo Months::getMonthInfo(MonthsEnum month) const {
		MonthInfo info;
		try {
			info = months.at(month);
		} catch (std::out_of_range e) {
			Logger::getInstance()->warning(std::string(
				"No month with value '" 
				+ std::to_string(month) 
				+ "' exists\n"
				+ "Using first month info").data());
			info = months.begin()->second;
		}

		return info;
	}
}