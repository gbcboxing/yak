import platform
import subprocess

if platform.system() == 'Windows':
  subprocess.run('cmake -B build/Windows')
if platform.system() == 'Darwin':
  subprocess.run('cmake -B build/macOS -G Xcode', shell=True)
else:
  print("Error: Operating system not supported!")
