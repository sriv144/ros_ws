#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64

class number_publishernode(Node):
    def __init__(self):
        super().__init__('number_publisher')

        self.number=2
        self.number_publisher=self.create_publisher(Int64, 'number', 10)
        self.timer=self.create_timer(0.5, self.publish_news)
        self.get_logger().info('Number Publisher has been started')
        
    def publish_news(self):
        msg=Int64()
        msg.data=self.number
        self.number_publisher.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = number_publishernode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
