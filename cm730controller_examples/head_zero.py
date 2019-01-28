import rclpy

from cm730controller_msgs.msg import MX28CommandArray, MX28Command

def main(args=None):
    rclpy.init(args=args)

    node = rclpy.create_node('head_zero_publisher')
    publisher = node.create_publisher(MX28CommandArray, '/cm730/mx28command')

    msg = MX28CommandArray(mx28s=[
        MX28Command(
            device_id=19,
            torque=True,
            led=False,
            d_gain=0,
            i_gain=0,
            p_gain=32,
            goal_position=0x800,
        ),
        MX28Command(
            device_id=20,
            torque=True,
            led=False,
            d_gain=0,
            i_gain=0,
            p_gain=32,
            goal_position=0x800,
        ),
    ])

    def timer_callback():
        node.get_logger().info('Publishing: {}'.format(msg))
        publisher.publish(msg)

    timer = node.create_timer(1, timer_callback)
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()