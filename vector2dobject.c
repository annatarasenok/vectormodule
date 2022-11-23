//Описание вектора
#include "vector2dobject.h"

//объявляет тип вектора для создания класса в питоне
PyTypeObject Vector2DType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "vector2d.Vector2D",
    .tp_doc = PyDoc_STR("Vector2D objects"),
    .tp_basicsize = sizeof(Vector2DObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = Vector2D_new,
    .tp_init = (initproc) Vector2D_init,
    .tp_dealloc = (destructor) Vector2D_dealloc,
    .tp_members = Vector2D_members,
};

//объявляет атрибуты вектора
PyMemberDef Vector2D_members[] = {
    {"x", T_FLOAT, offsetof(Vector2DObject, x), 0, "x value"},
    {"y", T_FLOAT, offsetof(Vector2DObject, y), 0, "y value"},
    {NULL},
};

//Инициализация вектора
int Vector2D_init(Vector2DObject *self, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {"x", "y", NULL};

    if(!PyArg_ParseTupleAndKeywords(args, kwds, "|ff", kwlist, &self->x, &self->y)) {
        return -1;
    }

    return 0;
}

//Инициализация вектора
PyObject * Vector2D_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    Vector2DObject *self = (Vector2DObject *) type->tp_alloc(type, 0);
    
    Vector2D_init(self, args, kwds);

    return (PyObject *) self;
}

//Создание вектора (Выделение памяти)
void Vector2D_dealloc(Vector2DObject *self) {
    Py_TYPE(self)->tp_free((PyObject *) self);
}

//Удаление вектора (Освобождение памяти)
float Vector2D_getattr(PyObject *object, const char *attr_name) {
    return PyFloat_AsDouble(PyObject_GetAttrString(object, attr_name));
}