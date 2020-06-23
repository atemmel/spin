#include <iostream>
#include <string_view>
#include <thread>

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

constexpr std::string_view Blue = "\033[0;36m";
constexpr std::string_view Green = "\033[0;32m";
constexpr std::string_view Reset = "\033[0m";
constexpr std::string_view Message = "Displaying cool message about what is going on...";

void blank(int n) {
	for(int i = 0; i < n; i++) {
		std::cout << "\b \b";
	}
}

void my_handler(int s){
	blank(Message.size() + 4);
	std::cout << Green << "✔" << Reset << " Whatever was going on is now completed!\n";
	exit(1); 
}

int main() {
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);


	for(int i = 0;;i++) {
		std::cout << Blue;
		switch(i) {
			case 0:
				std::cout << "⠙";
				break;
			case 1:
				std::cout << "⠹";
				break;
			case 2:
				std::cout << "⠸";
				break;
			case 3:
				std::cout << "⠼";
				break;
			case 4:
				std::cout << "⠴";
				break;
			case 5:
				std::cout << "⠦";
				break;
			case 6:
				std::cout << "⠧";
				break;
			case 7:
				std::cout << "⠇";
				break;
			case 8:
				std::cout << "⠏";
				break;
			case 9:
				std::cout << "⠋";
				break;
			default:
				i = -1;
				continue;
		}
		
		std::cout << Reset << ' ' << Message;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
		blank(Message.size() + 2);
	}
}
