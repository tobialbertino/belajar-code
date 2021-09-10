# method resolution order // multiple inheritance
# urutan method yg diambil / gunakan

class A:
    def show(self):
        print('ini adalah objek A')

class B:
    def show(self):
        print('ini adalah objek B')

class C(B, A):
    pass

object = C()
object.show()
