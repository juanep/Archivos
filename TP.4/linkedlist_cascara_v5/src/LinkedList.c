#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* list, int nodeIndex);
static int addNode(LinkedList* list, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* list;
    list = (LinkedList *)malloc(sizeof(LinkedList));
    if(list != NULL)
    {
        list->size=0;
        list->pFirstNode = NULL;
    }
    return list;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* list)
{
    int returnAux = -1;
    if(list != NULL)
    {
        returnAux = list->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* list, int nodeIndex)
{
    Node* pNode = NULL;
    int contador;
    if(list != NULL && nodeIndex >= 0 && nodeIndex < ll_len(list))
    {
        pNode = list->pFirstNode;
        for(contador = 0; contador < nodeIndex; contador++)
        {
            //reccore hasta uno antes del proximo
            pNode = pNode -> pNextNode;//nodo tiene la direccion del proximo nodo
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param list LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* list, int nodeIndex)
{
    return getNode(list, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* list, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = malloc(sizeof(Node));
    if(list != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(list))
    {   //estoy en condiciones de agregar un nodo.
        //para agregar un nodop tengo que preguntar en que posicion esta.
        if(list->pFirstNode == NULL && nodeIndex == 0)
        {   //agregar el primer nodo.
            list->pFirstNode = newNode;
            newNode->pElement = pElement;
            list->size = ll_len(list) + 1;
            returnAux = 0;
        }
        else
        {
            if(list->pFirstNode != NULL && nodeIndex == 0)
            {   //agrego un nodo al principio de la lista
                Node* oldFirstNode = list->pFirstNode;
                list->pFirstNode = newNode;
                list->pFirstNode->pNextNode = oldFirstNode;
                newNode->pElement = pElement;
                list->size = ll_len(list) + 1;
                returnAux = 0;
            }
            else
            {
                if(list->pFirstNode != NULL && nodeIndex > 0 && nodeIndex < ll_len(list))
                {   //agrego entre dos nodos
                    Node* oldNodeInIndex = getNode(list,nodeIndex);//traigo al ocupa de nodeIndex
                    newNode->pNextNode = oldNodeInIndex;   //el nuevo nodo tiene como siguiente al ocupa
                    Node* previousNode = getNode(list,nodeIndex - 1);  //traigo el nodo anterior a nodeIndex
                    previousNode->pNextNode = newNode;   //el nodo anterior a nodeIndex  tiene como siguiente al nuevo
                    newNode->pElement = pElement;
                    list->size = ll_len(list) + 1;
                    returnAux = 0;
                }
                else
                {
                    if(list->pFirstNode != NULL && nodeIndex == ll_len(list))
                    {   //agrego al final
                        Node* lastNode = getNode(list,nodeIndex - 1);//traigo al ultimo nodo
                        lastNode->pNextNode = newNode;   //el ultimo nodo tiene como siguiente al nuevo
                        newNode->pElement = pElement;
                        list->size = ll_len(list) + 1;
                        returnAux = 0;
                    }
                }
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* list, int nodeIndex,void* pElement)
{
    return addNode(list,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    if(list != NULL){
        addNode(list, list->size, pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* list, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;
    if(list != NULL && index >= 0 && index < ll_len(list))
    {
        auxNode = getNode(list, index);
        returnAux = auxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* list, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    if(list != NULL && index >= 0 && index < ll_len(list))
    {
        auxNode = getNode(list, index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* list,int index)
{
    int returnAux = -1;
    Node* auxNode = getNode(list, index);
    if(list != NULL && index >= 0 && index < ll_len(list))
    {
        if(index == 0)
        {
            list->pFirstNode = auxNode->pNextNode;
            free(auxNode);
            list->size = ll_len(list) - 1;
            returnAux = 0;
        }
        else
        {
            Node* previousNode = getNode(list, index - 1);
            previousNode->pNextNode = auxNode->pNextNode;
            free(auxNode);
            list->size = ll_len(list) - 1;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* list)
{
    int returnAux = -1;
    int contador;
    if(list != NULL)
    {
        for(contador = 0; contador < ll_len(list); contador++)
        {
            ll_remove(list, contador);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param list LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* list)
{
    int returnAux = -1;
    if(list != NULL)
    {
        ll_clear(list);
        free(list);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param list LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    int contador;
    if(list != NULL)
    {
        for(contador = 0; contador < ll_len(list); contador++)
        {
            auxNode = getNode(list, contador);
            if(auxNode->pElement == pElement){
                returnAux = contador;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param list LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* list)
{
    int returnAux = -1;
    if(list != NULL){
        if(list->size == 0){
            returnAux = 1;
        }
        else{
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* list, int index, void* pElement)
{
    int returnAux = -1;
    if(list != NULL && index >= 0 && index <= ll_len(list))
    {
        addNode(list, index, pElement);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param list LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* list,int index)
{
    void* returnAux = NULL;
    void* auxElement = NULL;
    if(list != NULL && index >= 0 && index < ll_len(list))
    {
        auxElement = ll_get(list, index);
        ll_remove(list, index);
        returnAux = auxElement;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param list LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    void* auxElement = NULL;
    int contador;
    if(list != NULL)
    {
        returnAux = 0;
        for(contador = 0; contador < ll_len(list); contador++)
        {
            auxElement = ll_get(list, contador);
            if(auxElement == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (list2)
            estan contenidos en la lista (list)
 *
 * \param list LinkedList* Puntero a la lista
 * \param list2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (list2) estan contenidos en la lista (list)
                        ( 0) si los elementos de (list2) NO estan contenidos en la lista (list)
*/
int ll_containsAll(LinkedList* list,LinkedList* list2)
{
    int returnAux = -1;
    void* auxElement = NULL;
    int contador;
    if(list != NULL && list2 != NULL)
    {
        returnAux = 1;
        for(contador = 0; contador < ll_len(list2); contador++)
        {
            auxElement = ll_get(list2, contador);
            if(!ll_contains(list, auxElement))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* list,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* list)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* list, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

