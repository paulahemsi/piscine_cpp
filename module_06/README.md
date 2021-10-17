# Module_06

* [c_type_conversion](#c_type_conversion)
* [c_type_reinterpretation](#c_type_reinterpretation)
* [c_type_qualifier_reinterpretation](#c_type_qualifier_reinterpretation)
* [upcast_and_downcast](#upcast_and_downcast)

* [exercises notes](#notes)

## c_type_conversion

```c++

int main(void)
{
	int a = 42;

	double b = a; // Implicit conersion cast 
	double c = (double)a; // Explicit conersion cast 

	double d = a; // Implicit promotion -> OK 
	int e = d; // Implicit demotion -> KO 
	int f = (int) d // Explicit demotion -> guarantee is a dev choice 
}

```
a: 00000000 00000000 00000000 00101010
b: 0 10000000100 0101000000000000000000000000000000000000000000000000
c: 0 10000000100 0101000000000000000000000000000000000000000000000000
d: 0 10000000100 0101000000000000000000000000000000000000000000000000
e: 00000000 00000000 00000000 00101010
f: 00000000 00000000 00000000 00101010

## c_type_reinterpretation

identity conversion

```c++

float a = 420.042f;

void *b = &a; // Implicit reintrepretetion
void *c = (void*)&a; //Explicit reinterpretation

void *d = &a; // Implicit promotion -> ok 
int  *e = d; // Implicit demotion -> KO 
int  *f = (int*)d; // Explicit demotion -> devs choice 

&a 0x7fff52
a  42.041992

b  0x7fff52
c  0x7fff52

d  0x7fff52
e  0x7fff52
*e 1137837408 //! totaly diferent number
f  0x7fff52
*f 1137837408 //! totaly diferent number

```

## c_type_qualifier_reinterpretation

the bits remain the same

```c++


int a = 420.042f;

int const *b = &a; // Implicit type qualifier cast
int const *c = (int const*)&a; //Explicit type qualifier cast

int const *d = &a; // Implicit promotion -> ok 
int  *e = d; // Implicit demotion -> KO compiler will refuse it because is a const, read only 
int  *f = (int*)d; // Explicit demotion -> devs choice, compilers does

//rare situation, maybe using a library that the programmer forgot to use const and you variable is const

```

## upcast_and_downcast

**c++**


