# diamond problem

class A:
    def show(self):
        print('ini adlah show A')

class B(A):
    def show(self):
        print('ini adlah show B')

class C(A):
    def show(self):
        print('ini adlah show C')

class D(B, C): # order : D B C A
    pass

object = D()
object.show()
help(object)