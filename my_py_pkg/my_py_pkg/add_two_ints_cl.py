#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial
from example_interfaces.srv import AddTwoInts

class AddTwoIntsClient(Node):
    def __init__(self):
        super().__init__('add_two_ints_client')
        self.client = self.create_client(AddTwoInts, 'add_two_ints')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        # Call the service with the desired values
        self.call_add_two_ints_server(5, 5)

    def call_add_two_ints_server(self, a, b):
        # Create a request object
        request = AddTwoInts.Request()
        request.a = a
        request.b = b

        # Call the service asynchronously and add the callback
        future = self.client.call_async(request)
        future.add_done_callback(partial(self.callback_call_add_two_ints_cl, a=a, b=b))

    def callback_call_add_two_ints_cl(self, future, a, b):
        try:
            # Get the response from the service call
            response = future.result()
            self.get_logger().info(f'{a} + {b} = {response.sum}')
        except Exception as e:
            self.get_logger().error(f'Service call failed: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClient()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
