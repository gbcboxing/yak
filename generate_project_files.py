import platform
import subprocess

if platform.system() == 'Windows':
  subprocess.run('cmake -B build')
