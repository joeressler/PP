import os
from PIL import Image
import PIL
from pathlib import Path

path_name = 'C:/Users/User/Downloads/overwatch-scoreboard-master/overwatch-scoreboard-master/assets/heroes/Icons-Heroes'

# path_name = os.path.realpath(path_name)


size = (112, 100)
folder = Path(path_name).glob('*')
for infile in folder:
    with Image.open(infile) as im:

        im.thumbnail(size)
        im = im.save(infile)
    
    