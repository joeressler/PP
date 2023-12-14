import os

path_name = 'C:/Users/User/Downloads/overwatch-scoreboard-master/overwatch-scoreboard-master/assets/heroes/3D'
path_name = os.path.realpath(path_name)

for count, filename in enumerate(os.listdir(path_name)):
    new = filename.removeprefix("3D-")
    src = os.path.join(path_name, filename)
    dst = os.path.join(path_name, new)
    os.rename(src, dst)
    
    