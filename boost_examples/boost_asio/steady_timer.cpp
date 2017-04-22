/*
The asio::steady_timer class is based on the std::chrono::steady_clock class,
which represents a steady clock that is not influenced by the system clock changes.
It means that asio::steady_timer is a good choice to measure intervals.
*/

#include <boost/asio/steady_timer.hpp>
#include <iostream>

using namespace boost;

int main()
{
	asio::io_service ios;

	asio::steady_timer t1(ios);
	t1.expires_from_now(std::chrono::seconds(2));

	asio::steady_timer t2(ios);
	t2.expires_from_now(std::chrono::seconds(5));

	t1.async_wait([&t2](boost::system::error_code ec) {
		if (ec == 0) {
			std::cout << "Timer #1 has expired!" << std::endl;
		}
		else if (ec == asio::error::operation_aborted) {
			std::cout << "Timer #1 has been canceled!"
				<< std::endl;
		}
		else {
			std::cout << "Error occurred! Error code = "
				<< ec.value()
				<< ". Message: " << ec.message()
				<< std::endl;
		}
		t2.cancel();
	});

	t2.async_wait([](boost::system::error_code ec) {
		if (ec == 0) {
			std::cout << "Timer #2 has expired!" << std::endl;
		}
		else if (ec == asio::error::operation_aborted) {
			std::cout << "Timer #2 has been canceled!"
				<< std::endl;
		}
		else {
			std::cout << "Error occurred! Error code = "
				<< ec.value()
				<< ". Message: " << ec.message()
				<< std::endl;
		}
	});
	ios.run();

	return 0;
}
