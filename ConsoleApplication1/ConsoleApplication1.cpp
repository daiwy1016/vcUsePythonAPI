// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <Python.h>

//Python c api使用方法

using namespace std;

string GetPyFun(string s1, string s2)
{
	// void Py_Initialize( )
	//初始化Python解释器，在C++程序中使用其它Python/C API之前，必须调用此函数，如果调用失败，将产生一个致命的错误
	Py_Initialize();

	//定义变量
	PyObject * pModule = NULL;
	PyObject * pFunc = NULL;
	PyObject * pArg = NULL;
	PyObject * result;
	char *resultStr = "";

	//int PyRun_SimpleString( const char *command)
	//直接执行一段Python代码，就好象是在__main__ 函数里面执行一样。
	//PyRun_SimpleString("import sys");
	//PyRun_SimpleString("sys.path.append('C:\\Documents and Settings\\Administrator\\My Documents\\Visual Studio 2005\\Projects\\hello\\hello')");

	//PyObject* PyImport_ImportModule(char *name)
	//导入一个Python模块，参数name可以是*.py文件的文件名。相当于Python内建函数__import__()
	pModule = PyImport_ImportModule("hello");//这里是要调用的文件名

											 //PyObject* PyObject_GetAttrString(PyObject *o, char *attr_name)
											 //返回模块对象o中的attr_name属性或函数，相当于Python中表达式语句：o.attr_name
	pFunc = PyObject_GetAttrString(pModule, "Hello");

	//PyObject* Py_BuildValue( char *format, ...)
	//format以tuple的形式指定，一个参数就是(i)
	//构建一个参数列表，把C类型转换为Python对象，使Python可以使用C类型数据
	pArg = Py_BuildValue("(s,s)", s1.c_str(), s2.c_str());

	//pParm = PyTuple_New(2);
	//PyTuple_SetItem(pParm, 0, Py_BuildValue("s", csEntity));
	//PyTuple_SetItem(pParm, 1, Py_BuildValue("s", csEntity));

	//PyObject* PyEval_CallObject(PyObject* pfunc, PyObject* pargs)
	//用于调用Python函数
	//此函数接受两个PyObject*形参
	//pfunc是要被调用的Python函数，通常可由PyObject_GetAttrString获得
	//pargs是函数的参数列表，通常可由Py_BuildValue获得
	result = PyEval_CallObject(pFunc, pArg);

	//int PyArg_Parse( PyObject *args, char *format, ...)
	//解构Python数据为C的类型，这样C程序中才可以使用Python里的数据。
	PyArg_Parse(result, "s", &resultStr);

	//关闭Python解释器，释放解释器所占用的资源
	Py_Finalize();
	return resultStr;
}

int Walk(const string& s1, const string& s2)
{
	// void Py_Initialize( )
	//初始化Python解释器，在C++程序中使用其它Python/C API之前，必须调用此函数，如果调用失败，将产生一个致命的错误
	Py_Initialize();

	//定义变量
	PyObject * pModule = NULL;
	PyObject * pFunc = NULL;
	PyObject * pArg = NULL;
	PyObject * result;
	int reVal = 0;

	//int PyRun_SimpleString( const char *command)
	//直接执行一段Python代码，就好象是在__main__ 函数里面执行一样。
	//PyRun_SimpleString("import sys");
	//PyRun_SimpleString("sys.path.append('C:\\Documents and Settings\\Administrator\\My Documents\\Visual Studio 2005\\Projects\\hello\\hello')");

	//PyObject* PyImport_ImportModule(char *name)
	//导入一个Python模块，参数name可以是*.py文件的文件名。相当于Python内建函数__import__()
	pModule = PyImport_ImportModule("walkdir");//这里是要调用的文件名

											   //PyObject* PyObject_GetAttrString(PyObject *o, char *attr_name)
											   //返回模块对象o中的attr_name属性或函数，相当于Python中表达式语句：o.attr_name
	pFunc = PyObject_GetAttrString(pModule, "list_dir");

	//PyObject* Py_BuildValue( char *format, ...)
	//format以tuple的形式指定，一个参数就是(i)
	//构建一个参数列表，把C类型转换为Python对象，使Python可以使用C类型数据
	pArg = Py_BuildValue("(s,s)", s1.c_str(), s2.c_str());

	//pParm = PyTuple_New(2);
	//PyTuple_SetItem(pParm, 0, Py_BuildValue("s", csEntity));
	//PyTuple_SetItem(pParm, 1, Py_BuildValue("s", csEntity));

	//PyObject* PyEval_CallObject(PyObject* pfunc, PyObject* pargs)
	//用于调用Python函数
	//此函数接受两个PyObject*形参
	//pfunc是要被调用的Python函数，通常可由PyObject_GetAttrString获得
	//pargs是函数的参数列表，通常可由Py_BuildValue获得
	result = PyEval_CallObject(pFunc, pArg);

	//int PyArg_Parse( PyObject *args, char *format, ...)
	//解构Python数据为C的类型，这样C程序中才可以使用Python里的数据。
	PyArg_Parse(result, "i", &reVal);

	//关闭Python解释器，释放解释器所占用的资源
	Py_Finalize();
	return reVal;
}

int main()
{
	/*cout<<"enter a path and a filename:"<<endl;
	string path,dir;
	cin>>path>>dir;
	int re=Walk(path,dir);*/
	/*
	Py_Initialize();
	PyRun_SimpleString("print 'hello world!' ");
	Py_Finalize();
	getchar();*/
	//初始化Python解释器，在C++程序中使用其它Python/C API之前，必须调用此函数，如果调用失败，将产生一个致命的错误
	Py_Initialize();
	//直接执行一段Python代码，就好象是在__main__ 函数里面执行一样。
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	
	//定义变量
	PyObject * pModule = NULL;
	PyObject * pFunc = NULL;
	PyObject * pArgs = NULL;
	PyObject * result;

	//导入一个Python模块，参数name可以是*.py文件的文件名。相当于Python内建函数__import__()
	pModule = PyImport_ImportModule("helloworld");

	//PyObject* PyObject_GetAttrString(PyObject *o, char *attr_name)
	//返回模块对象o中的attr_name属性或函数，相当于Python中表达式语句：o.attr_name
	pFunc = PyObject_GetAttrString(pModule, "hello");

	//format以tuple的形式指定，一个参数就是(i)
	//构建一个参数列表，把C类型转换为Python对象，使Python可以使用C类型数据
	//std::string cpp_string("daiwenyi");
	//pArgs = Py_BuildValue("s", cpp_string.c_str());

	//pParm = PyTuple_New(2);
	//PyTuple_SetItem(pParm, 0, Py_BuildValue("s", csEntity));
	//PyTuple_SetItem(pParm, 1, Py_BuildValue("s", csEntity));
	//char * csEntity = "daiwenyi";
	//std::string cpp_string("daiwenyi");
	pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", "dainnn"));
	//PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", csEntity));	
	//pfunc是要被调用的Python函数，通常可由PyObject_GetAttrString获得
	//pargs是函数的参数列表，通常可由Py_BuildValue获得
	PyEval_CallObject(pFunc, pArgs);
	Py_Finalize();
	system("pause");
    return 0;
}

int other_func() {
	//初始化python
	Py_Initialize();



	//定义python类型的变量
	PyObject *pModule = NULL;
	PyObject *pFunc = NULL;
	PyObject *pArg = NULL;
	PyObject *result = NULL;
	PyObject *pClass = NULL;
	PyObject *pInstance = NULL;
	PyObject *pDict = NULL;

	//直接运行python代码
	PyRun_SimpleString("print 'python start'");

	//引入模块
	pModule = PyImport_ImportModule("test_code");

	//获取模块字典属性
	pDict = PyModule_GetDict(pModule);

	//直接获取模块中的函数
	pFunc = PyObject_GetAttrString(pModule, "hello");

	//参数类型转换，传递一个字符串。将c/c++类型的字符串转换为python类型，元组中的python类型查看python文档
	pArg = Py_BuildValue("(s)", "hello charity");

	//调用直接获得的函数，并传递参数
	PyEval_CallObject(pFunc, pArg);

	//从字典属性中获取函数
	pFunc = PyDict_GetItemString(pDict, "arg");

	//参数类型转换，传递两个整型参数
	pArg = Py_BuildValue("(i, i)", 1, 2);

	//调用函数，并得到python类型的返回值
	result = PyEval_CallObject(pFunc, pArg);

	//c用来保存c/c++类型的返回值
	int c;

	//将python类型的返回值转换为c/c++类型
	//把Python数据类型解析为C的类型，这样C程序中才可以使用Python里面的数据。
	PyArg_Parse(result, "i", &c);

	//输出返回值
	printf("a+b=%d\n", c);



	//通过字典属性获取模块中的类
	pClass = PyDict_GetItemString(pDict, "Test");

	//实例化获取的类
	pInstance = PyInstance_New(pClass, NULL, NULL);

	//调用类的方法
	//PyObject_CallMethod(pClass, “class_method”, “O”, pInstance) 
	//参数分别为 PyObject（类），string（类方法），string（O表示参数为PyObject） ，PyObject（类实例）
	result = PyObject_CallMethod(pInstance, "say_hello", "(s)", "charity");

	//输出返回值

	char* name = NULL;

	PyArg_Parse(result, "s", &name);   //这个函数的第二个参数相当扯淡，具体看下文的英文，类型使用字符来表示的，例如“s”代表

									   //str "i" 代表int，个人感觉相当扯淡

	printf("%s\n", name);



	PyRun_SimpleString("print 'python end'");



	//释放python

	Py_Finalize();

	getchar();
	return 0;
}