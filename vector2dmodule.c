//Операции над векторами, добавление их в модуль,

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>
#include "vector2dobject.h"

//Сложение векторов
PyObject *Vector2D_add(PyObject *self, PyObject *vectors) {
    PyObject *vec1, *vec2;

    if(!PyArg_ParseTuple(vectors, "OO", &vec1, &vec2)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec1, "x") + Vector2D_getattr(vec2, "x");
    float y = Vector2D_getattr(vec1, "y") + Vector2D_getattr(vec2, "y");

    return Vector2D_new(&Vector2DType, Py_BuildValue("dd", x, y), NULL);
}

//Вычитание векторов
PyObject *Vector2D_substract(PyObject *self, PyObject *vectors) {
    PyObject *vec1, *vec2;

    if(!PyArg_ParseTuple(vectors, "OO", &vec1, &vec2)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec1, "x") - Vector2D_getattr(vec2, "x");
    float y = Vector2D_getattr(vec1, "y") - Vector2D_getattr(vec2, "y");

    return Vector2D_new(&Vector2DType, Py_BuildValue("dd", x, y), NULL);
}

//Умножение векторов
PyObject *Vector2D_multiply(PyObject *self, PyObject *vectors) {
    PyObject *vec1, *vec2;

    if(!PyArg_ParseTuple(vectors, "OO", &vec1, &vec2)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec1, "x") * Vector2D_getattr(vec2, "x");
    float y = Vector2D_getattr(vec1, "y") * Vector2D_getattr(vec2, "y");

    return Vector2D_new(&Vector2DType, Py_BuildValue("dd", x, y), NULL);
}

//Деление векторов
PyObject *Vector2D_divide(PyObject *self, PyObject *vectors) {
    PyObject *vec1, *vec2;

    if(!PyArg_ParseTuple(vectors, "OO", &vec1, &vec2)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec1, "x") / Vector2D_getattr(vec2, "x");
    float y = Vector2D_getattr(vec1, "y") / Vector2D_getattr(vec2, "y");

    return Vector2D_new(&Vector2DType, Py_BuildValue("dd", x, y), NULL);
}

//Получение длины одного вектора
PyObject *Vector2D_length(PyObject *self, PyObject *vector) {
    PyObject *vec;

    if(!PyArg_ParseTuple(vector, "O", &vec)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec, "x");
    float y = Vector2D_getattr(vec, "y");

    return PyFloat_FromDouble(sqrt(x*x + y*y));
}

//Нормализация вектора
PyObject *Vector2D_normalized(PyObject *self, PyObject *vector) {
    PyObject *vec;

    if(!PyArg_ParseTuple(vector, "O", &vec)) {
        return NULL;
    }

    float x = Vector2D_getattr(vec, "x");
    float y = Vector2D_getattr(vec, "y");
    float length = sqrt(x*x + y*y);

    return Vector2D_new(&Vector2DType, Py_BuildValue("dd", x * (1 / length), y * (1 / length)), NULL);
}

//Добавление методов в модуль
PyMethodDef vector2dmethods[] = {
    {"add", Vector2D_add, METH_VARARGS, "The method adds vectors"},
    {"substract", Vector2D_substract, METH_VARARGS, "The method subsracts vectors"},
    {"multiply", Vector2D_multiply, METH_VARARGS, "The method muliplies vectors"},
    {"divide", Vector2D_divide, METH_VARARGS, "The method devides vectors"},
    {"length", Vector2D_length, METH_VARARGS, "The method calculates length of vector"},
    {"normalized", Vector2D_normalized, METH_VARARGS, "The method returns normalized vector"},    
    {NULL},
};

//Создание модуля
static PyModuleDef vector2dmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "vector2d",
    .m_doc = "The C language module extension for vector 2D basic maths",
    .m_size = -1,
    vector2dmethods,
};

//Инициализация модуля
PyMODINIT_FUNC PyInit_vector2d(void) {
    if(PyType_Ready(&Vector2DType) < 0) {
        return NULL;
    }

    PyObject *vector2d_module = PyModule_Create(&vector2dmodule);//Выделение памяти под модуль

    if(vector2d_module == NULL) {
        return NULL;
    } 

    Py_INCREF(&Vector2DType);
    if(PyModule_AddObject(vector2d_module, "Vector2D", (PyObject *) &Vector2DType) < 0) {//Добавление класс вектор в модуль
        Py_DECREF(&Vector2DType);
        Py_DECREF(vector2d_module);
        return NULL;
    }

    return vector2d_module;
}