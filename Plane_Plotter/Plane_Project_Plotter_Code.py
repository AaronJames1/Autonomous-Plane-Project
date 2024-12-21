from pyautocad import Autocad, APoint
from pyproj import Proj, Transformer
import csv

# Initialize AutoCAD
acad = Autocad()

points = []

#Opening the CSV File
with open('test.csv') as file:
    data = csv.reader(file)
    for lines in data:
        x = lines[0]
        y = lines[1]

        # Convert from WGS84 to Web Mercator (meters)
        transformer = Transformer.from_crs('EPSG:4326', 'EPSG:3857')
        lat, lon = transformer.transform(x, y)

        # Creates and stores point
        point = APoint(lat, lon)
        points.append(point)

for i in range(len(points)-1):

    # Plot the point in AutoCAD
    acad.model.AddPoint(point)

    # Plot the lines in AutoCAD
    acad.model.AddLine(points[i],points[i+1])

print("complete")
