import requests
from bs4 import BeautifulSoup

response = requests.get("https://www.google.com/search?client=firefox-b-d&q=jack+ma+transcript")

print(response.content)