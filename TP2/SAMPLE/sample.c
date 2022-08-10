#include <stdio.h>
#include <stdlib.h>

typedef struct punto t_punto;
struct punto
{
	int x;
	int y;
	t_punto* siguiente;
};

void
mostrar(t_punto* elem)
{
	if (elem != NULL)
	{
		printf ("(%d, %d)\n", elem->x, elem->y);
	}
	else
	{
		printf ("El elemento no existe.\n");
	}
}

void
recorrer(t_punto *elem)
{
	if (elem == NULL)
	{
		printf ("La cola está vacía.\n");
	}
	else
	{
		for (t_punto *tmp = elem; tmp != NULL; tmp = tmp->siguiente)
		{
			mostrar(tmp);
		}
	}
}

void
crear(t_punto **elem)
{
	(*elem) = (t_punto*) malloc(sizeof(t_punto));
}

void
leer(t_punto *elem)
{
	int x;
	int y;
	printf ("Ingrese un valor para x: ");
	scanf ("%d", &x);
	printf ("Ingrese un valor para y: ");
	scanf ("%d", &y);
	elem->x = x;
	elem->y = y;
	elem->siguiente = NULL;
}

void
insertar_inicio(t_punto **cabeza, t_punto *elem)
{
	if ((*cabeza) == NULL)
	{
		(*cabeza) = elem;
	}
	else
	{
		elem->siguiente =  (*cabeza);
		(*cabeza) = elem;
	}
}

void
insertar_final(t_punto **cabeza, t_punto *elem)
{
	if ((*cabeza) == NULL)
	{
		(*cabeza) = elem;
	}
	else
	{
		t_punto *tmp;
		for (tmp = (*cabeza); tmp->siguiente != NULL; tmp = tmp->siguiente);
		tmp->siguiente = elem;
	}
}


int
main()
{
	t_punto* cabeza = NULL;
	t_punto* elem = NULL;

	recorrer(cabeza);

	crear(&elem);
	leer(elem);
	insertar_inicio(&cabeza, elem);
	recorrer(cabeza);

	crear(&elem);
	leer(elem);
	insertar_inicio(&cabeza, elem);
	recorrer(cabeza);

	crear(&elem);
	leer(elem);
	insertar_final(&cabeza, elem);
	recorrer(cabeza);

	exit(0);
}