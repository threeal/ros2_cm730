// Copyright 2019 Bold Hearts
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "imu_publisher/imu_publisher.hpp"

namespace imu_publisher
{

IMUPublisher::IMUPublisher()
: rclcpp::Node{"imu_publisher"}
{
    imuStatePub_ = create_publisher<sensor_msgs::msg::Imu>("/Imu");

    cm730InfoSub_ = create_subscription<cm730controller_msgs::msg::CM730Info>(
        "/cm730/cm730info",
        [ = ](cm730controller_msgs::msg::CM730Info::SharedPtr info) {
          auto imuStateMsg = std::make_shared<sensor_msgs::msg::Imu>();

          imuStateMsg->header = info.get()->header;
          imuStatePub_->publish(imuStateMsg);
        });
}

IMUPublisher::~IMUPublisher()
{
}

}  // namespace imu_publisher
