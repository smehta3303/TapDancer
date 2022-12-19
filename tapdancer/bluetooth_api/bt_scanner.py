from bleak import BleakScanner, BleakClient
import asyncio

async def scan_devices():
    """
    Scans for BT servers and displays a list
    """
    print('Scanning for devices')
    devices = await BleakScanner.discover(timeout=15.0)
    for device in devices:
        print(device)
    print(len(devices), "Devices found!")

if __name__ == '__main__':
     asyncio.run(scan_devices())