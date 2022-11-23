import vector2d

def str_vector(vector):
    return str(vector.x) + " " + str(vector.y)

vector1 = vector2d.Vector2D(2, 7)
vector2 = vector2d.Vector2D(3, 4)

print("Add vectors: ", str_vector(vector2d.add(vector1, vector2)))
print("Substract vectors: ", str_vector(vector2d.substract(vector1, vector2)))
print("Multiply vectors: ", str_vector(vector2d.multiply(vector1, vector2)))
print("Divide vectors: ", str_vector(vector2d.divide(vector1, vector2)))

print("Length of vector: ", vector2d.length(vector1))
print("Normalized vectors: ", str_vector(vector2d.normalized(vector1)))