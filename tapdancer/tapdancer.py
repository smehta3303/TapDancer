import asyncio
from bluetooth_api import bt_scanner

if __name__ == "__main__":
    asyncio.run(bt_scanner.scan_devices())