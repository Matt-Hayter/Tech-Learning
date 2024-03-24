"""
Most python APIs are synchronous by default, whereas JS APIs tend to be aynchronous by default.
As python is generally backend, the synchronous "request" library is normally used for !recieving! requests
"""

"""
Asynchronous requests
"""
import asyncio #For async await functions
import aiohttp #For async requests (default is sync in python)
import json #For parsing json data string sent over API

async def async_function():
  some_url = "https://idneidneden"
  #Use asynchronous get request
  async with aiohttp.ClientSession() as session:
    async with session.get("https://reqres.in/api/users?page=2") as response: #Say this returns some JSON object, which is represented as a string in python (eg. '{"name": "Bob", "languages": ["English", "French"]}')
      res = await response.read()
      print("Response from server read")
      print(json.loads(res)) #Convert JSON String to dictionary

if __name__ == "__main__":
  asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy()) # Avoids bug for windows
  asyncio.run(async_function()) # Run coroutine as a task. Async functions need to be run explicitly.