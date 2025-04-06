#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "feature.c"

static PyObject* wrap_roll(PyObject* self, PyObject* args) {
    PyObject *input;
    int window;
    if (!PyArg_ParseTuple(args, "Oi", &input, &window)) return NULL;

    Py_ssize_t len = PyList_Size(input);
    double* in = malloc(len * sizeof(double));
    double* out = malloc(len * sizeof(double));

    for (Py_ssize_t i = 0; i < len; i++) {
        in[i] = PyFloat_AsDouble(PyList_GetItem(input, i));
    }

    rolling_mean(in, (int)len, window, out);

    PyObject* result = PyList_New(len);
    for (Py_ssize_t i = 0; i < len; i++) {
        if (isnan(out[i]))
            PyList_SetItem(result, i, PyFloat_FromDouble(NAN));
        else
            PyList_SetItem(result, i, PyFloat_FromDouble(out[i]));
    }

    free(in); free(out);
    return result;
}

static PyObject* wrap_mom(PyObject* self, PyObject* args) {
    PyObject *input;
    int window;
    if (!PyArg_ParseTuple(args, "Oi", &input, &window)) return NULL;

    Py_ssize_t len = PyList_Size(input);
    double* in = malloc(len * sizeof(double));
    double* out = malloc(len * sizeof(double));

    for (Py_ssize_t i = 0; i < len; i++) {
        in[i] = PyFloat_AsDouble(PyList_GetItem(input, i));
    }

    momentum(in, (int)len, window, out);

    PyObject* result = PyList_New(len);
    for (Py_ssize_t i = 0; i < len; i++) {
        if (isnan(out[i]))
            PyList_SetItem(result, i, PyFloat_FromDouble(NAN));
        else
            PyList_SetItem(result, i, PyFloat_FromDouble(out[i]));
    }

    free(in); free(out);
    return result;
}

static PyObject* wrap_zscore(PyObject* self, PyObject* args) {
    PyObject *input;
    int window;
    if (!PyArg_ParseTuple(args, "Oi", &input, &window)) return NULL;

    Py_ssize_t len = PyList_Size(input);
    double* in = malloc(len * sizeof(double));
    double* out = malloc(len * sizeof(double));

    for (Py_ssize_t i = 0; i < len; i++) {
        in[i] = PyFloat_AsDouble(PyList_GetItem(input, i));
    }

    zscore(in, (int)len, window, out);

    PyObject* result = PyList_New(len);
    for (Py_ssize_t i = 0; i < len; i++) {
        if (isnan(out[i]))
            PyList_SetItem(result, i, PyFloat_FromDouble(NAN));
        else
            PyList_SetItem(result, i, PyFloat_FromDouble(out[i]));
    }

    free(in); free(out);
    return result;
}

static PyMethodDef FeatureMethods[] = {
    {"rolling_mean", wrap_roll, METH_VARARGS, "Rolling mean"},
    {"momentum", wrap_mom, METH_VARARGS, "Momentum"},
    {"zscore", wrap_zscore, METH_VARARGS, "Z-score"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef featuremodule = {
    PyModuleDef_HEAD_INIT, "feature", "Alpha feature module", -1, FeatureMethods
};

PyMODINIT_FUNC PyInit_feature(void) {
    return PyModule_Create(&featuremodule);
}