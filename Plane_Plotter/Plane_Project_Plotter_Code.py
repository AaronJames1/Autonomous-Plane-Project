from pyautocad import Autocad, APoint

# Initialize AutoCAD
acad = Autocad()

# Get user input
x = float(input("Enter X coordinate: "))
y = float(input("Enter Y coordinate: "))

# Create an AutoCAD point
point = APoint(x, y)

# Plot the point in AutoCAD
acad.model.AddPoint(point)
