import asyncio
from bluetooth_api.bt_scanner import BT

if __name__ == "__main__":
    bt_device = BT()
    asyncio.run(bt_device.discover_devices())
    bt_device.print_devices()