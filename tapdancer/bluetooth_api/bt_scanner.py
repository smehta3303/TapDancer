from bleak import BleakScanner, BleakClient
import asyncio


class BT:
    def __init__(self):
        __discovered_devices = []

    async def __scan_devices(self, timeout=15.0):
        """
        Scans for BT servers and displays a list
        """
        print('Scanning for devices')
        devices = await BleakScanner.discover(timeout)
        return devices

    async def discover_devices(self):
        self.__discovered_devices = await self.__scan_devices(timeout=30.0)

    def connect_to_device(self, device_address):
        pass

    def print_devices(self):
        for device in self.__discovered_devices:
            print(device)



if __name__ == '__main__':
    bluetooth_device = BT()
    asyncio.run(bluetooth_device.scan_devices())