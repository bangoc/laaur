/*
 * Minh họa tạo mô-đun mở rộng cho Python bằng C
 * (C) Nguyễn Bá Ngọc, 2023
 */
#include <Python.h>

// Hàm tìm ước số chung lớn nhất
static PyObject *uscln(PyObject *self, PyObject *args) {
  int a, b;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return Py_BuildValue("i", a);
}

// Các mô tả hàm
static const char mota_uscln[] = 
    "Hàm tìm Ước số chung lớn nhất của 2 số nguyên dương";

// Ánh xạ hàm Python và hàm C
static PyMethodDef tap_phuong_thuc[] = {
  {.ml_name  = "uscln",      .ml_meth = uscln, 
   .ml_flags = METH_VARARGS, .ml_doc  = mota_uscln},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef sohoc = {
  PyModuleDef_HEAD_INIT,
  .m_name = "sohoc",
  .m_doc = "Thư viện số học.",
  .m_size = -1,
  .m_methods = tap_phuong_thuc
};

PyMODINIT_FUNC PyInit_sohoc() {
  return PyModule_Create(&sohoc);
}
