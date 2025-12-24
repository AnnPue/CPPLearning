import qrcode
import os

url = 'https://www.bilibili.com/video/BV16oKuzoEia'
img = qrcode.make(url)
file_path = r".\PY\qr.png"
img.save(file_path, 'PNG')
os.startfile(file_path)