from pyautocad import Autocad, APoint
from pyproj import Proj, Transformer

# Initialize AutoCAD
acad = Autocad()

while True:

    # Get user input 
    x = float(input("Enter Latitude coordinate: "))
    y = float(input("Enter Longitude coordinate: "))

    # Convert from WGS84 to Web Mercator (meters)
    transformer = Transformer.from_crs('EPSG:4326', 'EPSG:3857')
    lat, lon = transformer.transform(x, y)

    # Create an AutoCAD point
    point = APoint(lat, lon)

    # Plot the point in AutoCAD
    acad.model.AddPoint(point)