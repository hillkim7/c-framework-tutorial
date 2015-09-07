#include <boost/log/core.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/shared_ptr.hpp>
#include <unistd.h>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;

class customlog_sink : public sinks::basic_formatted_sink_backend<char, sinks::concurrent_feeding>
{
public:
   void consume(const logging::record_view& rec, const string_type& fstring)
   {
      std::cout << "<" << rec[boost::log::trivial::severity] << "> " << fstring << std::endl;
   }
};


void init_log()
{
   typedef sinks::synchronous_sink< customlog_sink > sink_t;


   boost::shared_ptr< sink_t > sink(new sink_t());
   boost::shared_ptr< logging::core > core = logging::core::get();

   core->add_sink(sink);
}

int main()
{
   logging::add_common_attributes();
   init_log();
   BOOST_LOG_TRIVIAL(warning) << "warning message";
   BOOST_LOG_TRIVIAL(error) << "error message";

   return 0;
}
