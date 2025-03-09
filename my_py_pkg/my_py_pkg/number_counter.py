#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64

class number_counternode(Node):
    def __init__(self):
        super().__init__('number_counter')
        self.number_counter=self.create_subscription(Int64, 'number', self.number_callback, 10)
        self.counter=0
        self.number_count_publisher=self.create_publisher(Int64, 'number_count', 10)
        self.get_logger().info('Number counter has been started')
        
    def number_callback(self, msg):
        self.counter+=msg.data
        new_msg=Int64()
        new_msg.data=self.counter
        self.number_count_publisher.publish(new_msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = number_counternode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()