#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

unsigned int line_print_counter {0};
const unsigned int space_weekdays {8};
const unsigned int space_days {8};

void clear_line() {
    line_print_counter = 0;
    std::cout << std::endl;
}

void padding(int limit) {
    for(size_t i = 0; i<limit; i++) {
        std::cout << std::setw(space_days) << " ";
        line_print_counter++;
    }
}

// given: Februrary-28
// returns: February
std::string parse_month(std::string month_and_limit) {
    return month_and_limit.substr(0, month_and_limit.length() -3);
}

// given: Februrary-28
// returns: 28
int parse_days(std::string month_and_limit) {
    return stoi(month_and_limit.substr(month_and_limit.length() -2, month_and_limit.length()));
}

int find_index_of(std::vector<std::string> array, std::string target) {
    for(size_t index {0}; index<array.size(); index++) {
        if(array.at(index) == target) return index;
    }
    return -1;
}

void print(std::string text) {
    std::cout << text;
}

void print(int numeric) {
    print(std::to_string(numeric));
}

void print_line(std::string text) {
    print(text);
    clear_line();
}

void print_weekdays(std::vector<std::string> weekdays) {
    for(auto weekday : weekdays) {
        std::cout << std::setw(space_weekdays) << weekday;
    }
    clear_line();
}

void print_days(int day) {
    std::cout << std::setw(space_days) << day;
}

bool is_leap_year(unsigned int year) {
    return !(year % 4); // I know it's not perfect
}


int main() {

    unsigned int year {1900};
    unsigned int first_day_of_year {0};
    bool first_month_printed = {false};
    bool is_leap {false};
    unsigned int restore_print_line_counter {0};

     std::vector<std::string> months =  {"January-31", 
                                        "February-28", // Check if it's a leap year
                                        "March-31", 
                                        "April-30", 
                                        "May-31", 
                                        "June-30", 
                                        "July-31", 
                                        "August-31", 
                                        "September-30", 
                                        "October-31", 
                                        "November-30", 
                                        "December-31"};

    std::vector<std::string> weekdays = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    print("Enter a year: ");
    std::cin >> year;
    is_leap = is_leap_year(year);
    
    print("Enter the first day of the year [1: Monday, ... 7:Sunday] : ");
    std::cin >> first_day_of_year;

    clear_line();
    clear_line();

    print_line("Calendar for " + std::to_string(year));

    for(auto raw : months) {
        std::string current_month = parse_month(raw);
        size_t month_limit = parse_days(raw);

        // Check for leap year
        if(current_month == "February" && is_leap)
                month_limit = 29;
        
        // Printing current month
        print_line("-- " + current_month + " --");
        // Printing the weekdays
        print_weekdays(weekdays);
        if(!first_month_printed) 
            padding(first_day_of_year - 1);
        else {
            padding(restore_print_line_counter);
        }

        std::cout << std::setw(space_days);
        for(int day_counter {1}; day_counter<=month_limit; day_counter++) {
            if(line_print_counter == 7) clear_line();
            print_days(day_counter);
            line_print_counter++;
            first_month_printed = true;
            restore_print_line_counter = line_print_counter;
        }

        clear_line();
        clear_line();
        clear_line();
        
    }
    

    return 0;
}
