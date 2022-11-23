//Определяет Объект Вектор
#ifndef VECTOR_2D_TYPE
#define VECTOR_2D_TYPE

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

//Вектор
typedef struct {
    PyObject_HEAD
    float x;
    float y;
} Vector2DObject;

//объявляет тип вектор для создания класса в питоне
extern PyTypeObject Vector2DType;

//объявляет атрибуты вектора
extern PyMemberDef Vector2D_members[];

//Инициализация вектора
int Vector2D_init(Vector2DObject *self, PyObject *args, PyObject *kwds);

//Создание вектора (Выделение памяти)
PyObject *Vector2D_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

//Удаление вектора (Освобождение памяти)
void Vector2D_dealloc(Vector2DObject *self);

//Получение атрибута вектора
float Vector2D_getattr(PyObject *object, const char *attr_name);

#endif