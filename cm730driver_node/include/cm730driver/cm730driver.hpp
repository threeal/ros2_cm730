#ifndef CM730DRIVER__CM730DRIVER_HPP_
#define CM730DRIVER__CM730DRIVER_HPP_

#include <rclcpp/rclcpp.hpp>
#include "cm730driver/visibility_control.h"
#include "cm730driver_msgs/srv/ping.hpp"
#include "cm730driver_msgs/srv/read.hpp"
#include "cm730driver_msgs/srv/write.hpp"
#include "cm730driver_msgs/srv/bulk_read.hpp"
#include "cm730driver_msgs/srv/sync_write.hpp"


namespace cm730driver
{

  class Cm730Device;
  class PingService;
  class ReadService;
  class WriteService;
  class BulkReadService;
  class SyncWriteService;
  
  class Cm730Driver : public rclcpp::Node
  {
  public:
    Cm730Driver();
    
    virtual ~Cm730Driver();

  private:
    std::shared_ptr<Cm730Device> mDevice;

    std::tuple<std::shared_ptr<PingService>,
               rclcpp::Service<cm730driver_msgs::srv::Ping>::SharedPtr> mPingServer;

    std::tuple<std::shared_ptr<ReadService>,
               rclcpp::Service<cm730driver_msgs::srv::Read>::SharedPtr> mReadServer;

    std::tuple<std::shared_ptr<WriteService>,
               rclcpp::Service<cm730driver_msgs::srv::Write>::SharedPtr> mWriteServer;

    std::tuple<std::shared_ptr<BulkReadService>,
               rclcpp::Service<cm730driver_msgs::srv::BulkRead>::SharedPtr> mBulkReadServer;

    std::tuple<std::shared_ptr<SyncWriteService>,
               rclcpp::Service<cm730driver_msgs::srv::SyncWrite>::SharedPtr> mSyncWriteServer;
  };
  
}  // namespace cm730driver

#endif  // CM730DRIVER__CM730DRIVER_HPP_
