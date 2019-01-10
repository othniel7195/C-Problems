# C-Problems

1.构造函数加初始化列表 ：complex(double r= 0, double i = 0) :rel(r), img(i) {}

2.inline 内联函数 必选定义和实现都在.h 中不能 定义和实现分开在.h 和 .cpp中

3.complex& operator ++ ();// 重载的是 ++a 而不是a++

4.（ << ）重载，需要些类外部。ostream & os 作为第一参数。若是些在类内部，this默认第一个参数就会变成 a<<cout 这样输出。

5. 参数 能用引用的最好用引用，不需要改变的加const:complex& operator += (const complex& c2);

6. 返回值如果不是函数内部零时的 用引用返回complex& operator += (const complex& c2);

7. 返回的值不让改变的 中间加const ：double real() const { return rel; };

8. 返回值是local object （离开函数被释放的），不能用引用，要用值传递。

9.定义的函数参数有默认值 ，实现就不能再写默认值。

10.赋值copy需要先检查自我赋值，然后delete自己。

11.char *a, a 的长度记得+1 ，最后加个'\0',strlen计算的是没后’\0‘的

12. 数组new 后释放用delete[]

