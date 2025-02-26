import os
from os import listdir

my_path = './'

for file_name in listdir(my_path):

    if file_name.endswith('.a') or file_name.endswith('.exe') or file_name.endswith('.o'):
        os.remove(my_path + file_name)