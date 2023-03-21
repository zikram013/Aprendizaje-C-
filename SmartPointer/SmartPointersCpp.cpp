#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <thread>
using namespace std::chrono_literals;
using namespace std;
//Linked list
class Node {
public:
	int Value;
	Node* Next;
};

class NodeDoubleLinkedList {
public:
	int Value;
	NodeDoubleLinkedList* Previous;
	NodeDoubleLinkedList* Next;
};

struct NodeBinaryTree
{
	int data;
	NodeBinaryTree* left;
	NodeBinaryTree* right;
};

NodeBinaryTree* createNode(int data){
	NodeBinaryTree* newNode = new NodeBinaryTree();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

//Operator overloading
struct YouTubeChannel {
	string Name;
	int SubscribersCount;

	YouTubeChannel(string name, int susbscriberCount) {
		this->Name = name;
		this->SubscribersCount = susbscriberCount;
	}
	bool operator==(const YouTubeChannel&channel)const {
		return this->Name == channel.Name;
	}
};
struct MyCollection {
	list<YouTubeChannel>myChannels;
	void operator+=(YouTubeChannel& channel) {
		this->myChannels.push_back(channel);
	}
	void operator-=(YouTubeChannel& channel) {
		this->myChannels.remove(channel);
	}
};
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
	COUT << "Name: " << ytChannel.Name << endl;
	COUT << "NSusbriber" << ytChannel.SubscribersCount << endl;
	return COUT;
};

ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
	for (YouTubeChannel ytChannel : myCollection.myChannels) {
		COUT << ytChannel << endl;
	}
	return COUT;
}
//Estructura de datos para almacenar un borde de grafo
struct Edge {
	int src;
	int dest;
};

class Graph {
public:
	//Un vector de vectores para representar una lista de adyacencia
	vector<vector<int>>adjList;
	//Contructor del grafo
	Graph(vector<Edge>const& edges, int n) {
		//Cambiar el tamaño del vector para contener n elementos de tipo vector<int>
		adjList.resize(n);
		//agrega bordes al grafo no dirigido
		for (auto& edge : edges) {
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

void DFS(Graph const& graph, int v, vector<bool> &discovered) {
	if (discovered[v])return;
	discovered[v] = true;
	for (int i = 0; i < graph.adjList[v].size(); i++) {
		int u = graph.adjList[v][i];
		DFS(graph,u,discovered);//lo visitamos
	}
}

void BFS(Graph const &graph,int v,vector<bool> &dicovered) {
	//creamos una cola para hacer BFS
	queue<int>q;
	//Marca el vértice de origen como descubierto
	dicovered[v] = true;
	//Poner en la cola el vertice fuente
	q.push(v);
	//buclce hasta que la cola este vacia
	while (!q.empty()) {
		//quitar de la cola del nodo frontal e imprimirlo
		v = q.front();
		q.pop();
		cout << v << " ";
		//hacer para cada borde (v,u)
		for (int u : graph.adjList[v]) {
			if (!dicovered[u]) {
				//marcarlo como visitado y ponerlo en la cola
				dicovered[u] = true;
				q.push(u);
			}
		}
	}
}
//Hilos
void functionThread1(char symbol) {
	for (int i = 0; i < 200; i++) {
		cout << symbol;
	}
}

void functionThread2() {
	for (int i = 0; i < 200; i++) {
		cout << "-";
	}
}

void RefreshForecast(map<string, int>forecastMap) {
	for (auto& item : forecastMap) {
		item.second++;
		cout << item.first << " " << item.second<<endl;
	}
	this_thread::sleep_for(2000ms);
}

//Arboles
void printTreePreorden(NodeBinaryTree* root) {
	if (root == nullptr)return;
	cout << root->data << endl;
	printTreePreorden(root->left);
	printTreePreorden(root->right);
}

void printTreeInorden(NodeBinaryTree* root) {
	if (root == nullptr)return; 
	printTreeInorden(root->left);
	cout << root->data << endl;
	printTreeInorden(root->right);
}

void printTreePostorden(NodeBinaryTree* root) {
	if (root == nullptr)return;
	printTreeInorden(root->left);
	printTreePostorden(root->right);
	cout << root->data << endl;
}

void printList(Node*n) {
	while (n!= NULL) {
		cout << n->Value << " ";
		n = n->Next;
	}
	cout << endl;
}

void printForward(NodeDoubleLinkedList* head) {
	NodeDoubleLinkedList* traverser = head;
	while (traverser != nullptr) {
		cout << traverser->Value << endl;
		traverser = traverser->Next;
	}
}

void printBackward(NodeDoubleLinkedList* tail) {
	NodeDoubleLinkedList* traverser = tail;
	while (traverser != nullptr) {
		cout << traverser->Value << endl;
		traverser = traverser->Previous;
	}
}

void insertAtTheFront(Node**head,int newValue) {
	//1.Preparamos el nuevo nodo
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = *head;
	*head = newNode;
}

void insertAtTheEnd(Node** head, int newValue) {
	//Preparamos en nuevo nodo
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->Next = NULL;
	//Si esta vacia es el primer elemento
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	//Encuentra el ultimo
	Node* last = *head;
	while (last->Next!=NULL) {
		last = last->Next;
	}
	//Inserta el nodo
	last->Next = newNode;
}

void insertAfter(Node* previus, int newValue) {
	//comprobamos si el nodo previo es nullo
	if (previus == NULL) {
		cout << "El nodo previo no puede ser null" << endl;
		return;
	}
	//Preparamos el nuevo nodo
	Node* newNode = new Node();
	newNode->Value = newValue;
	//Insertar el nuevo nodo despues del nodo previo pasado por parametro
	newNode->Next = previus->Next;
	previus->Next = newNode;
}

//Pasamos por parámetro la direccion de la variable
void printNumber(int* numberPtr) {
	cout << *numberPtr << endl;
}

void printCharacter(char* letterPtr) {
	cout << *letterPtr << endl;
}

void print(void* ptr, char type) {
	switch (type)
	{
		//en el caso de que en el cast pongamos un tipo de parametro que no se corresponde dara un caracter raro o undefined y el compilador no muestra error
		case'i':
			//handle int*
			cout << *((int*)ptr) << endl;//castea el puntero void al parametro
			break;
		case 'c':
			//handle char*
			cout << *((char*)ptr) << endl;//Castea el puntero void al parametro
			break;
		default:
			break;
	}
}

int getMin(int numbers[], int size) {
	int minValue = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] < minValue) {
			minValue = numbers[i];
		}
	}
	return minValue;
}

int getMax(int numbers[], int size) {
	int maxValue = numbers[0];
	for (int i = 1; i < size; i++) {
		if (maxValue < numbers[i]) {
			maxValue = numbers[i];
		}
	}
	return maxValue;
}

void getMinAndMax(int numbers[], int size,int*min,int*max) {
	for (int i = 1; i < size; i++) {
		if (numbers[i] > *max) {
			*max = numbers[i];
		}
		if (numbers[i] < *min) {
			*min = numbers[i];
		}
	}
}

int getNumber() {
	return 5;
}

int add(int a,int b){
	return a + b;
}

bool ascendingCompare(int a, int b) {
	return a < b;
}

bool descendingCompare(int a, int b) {
	return a > b;
}

void sortAscending(vector<int>& numbersVector) {
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++) {
		int bestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++) {
			//we are doing comparison here
			if (ascendingCompare(numbersVector[currentIndex], numbersVector[bestIndex])) {
				bestIndex = currentIndex;
			}
		}
		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}

void sortDescending(vector<int>& numbersVector) {
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++) {
		int bestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++) {
			if (descendingCompare(numbersVector[currentIndex], numbersVector[bestIndex])) {
				bestIndex = currentIndex;
			}
		}
		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}

void printVectorNumbers(vector<int>& numbersVector) {
	for (int i = 0; i < numbersVector.size(); i++) {
		cout << numbersVector[i] << " ";
	}
	cout << endl;
}

void customSort(vector<int>& numbersVector,bool(*compareFuncPtr)(int,int)) {
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++) {
		int bestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++) {
			if (compareFuncPtr(numbersVector[currentIndex], numbersVector[bestIndex])) {
				bestIndex = currentIndex;
			}
		}
		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}

class MyClass {
public:
	//constructor
	MyClass(){
		cout << "Constructor invoked" << endl;
	}

	//Destructor
	~MyClass() {
		cout << "Destructor invoked" << endl;
	}
};

int main(){
	//tutorial de codeBeauty sobre pointers
	cout << endl << "Iniciar punteros" << endl;
	int n = 5;
	cout << &n << endl;//Obtenemos la direccion
	int* ptr = &n; //Almacenamos la direccion de la variable
	cout << ptr << endl;
	cout << *ptr << endl; //Devuelve el valor que almacena la direccion de memoria
	*ptr = 10; //esto cambia el valor de la variable almacenado en la direccion de memoria asignada para dicha variable
	cout << *ptr << endl; 
	//Al no estar el puntero apuntando a la direccion de la variable, este no puede realizar modificaciones sobre esta, por lo que debemos crear la variable y luego asignar su direccion de memoria al puntero
	int v;
	int* ptr2 = &v;
	*ptr2 = 7;
	cout << "v=" << v << endl;

	cout << endl << "Void punteros" << endl;
	int  number = 5;
	char letter = 'a';
	printNumber(&number);
	printCharacter(&letter);
	print(&number, 'i');
	print(&letter, 'c');

	cout << endl << "How to use pointers with arrays" << endl;
	int luckyNumbers[5] = { 2,3,5,7,9 };
	cout << luckyNumbers << endl;//Nos da la direccion del primer elemento del array
	cout << &luckyNumbers[0] << endl; //Misma situacion que la anterior
	cout << luckyNumbers[2] << endl;//Obtenemos el elemento de esa posicion
	cout << *(luckyNumbers + 2) << endl; //mismo caso que el anterior

	//int luckyNumber2[5];
	//for (int i = 0; i <= 4; i++) {
	//	cout << "Number: ";
	//	cin >> luckyNumber2[i];
	//}

	//for (int i = 0; i <= 4; i++) {
	//	cout << *(luckyNumber2 + i) << " ";// Si ponemos un for mas grande a la capacidad establecida, los valores que se pasen tendrán valores basura
	//}

	cout << endl << "Return multiplie values from a function using pointer" << endl;
	int numbers[5] = { 5,4,-2,29,6 };
	cout << "The min value is: " << getMin(numbers, 5) << endl;
	cout << "The max value is: " << getMax(numbers, 5) << endl;
	int min = numbers[0];
	int max = numbers[0];
	getMinAndMax(numbers, 5, &min, &max);//Se estan pasando las referencias de las variables, lo que ayuda a modificar sus valores en el metodo y utilizarlos cuando sea necesario
	cout << "Min is: " << min << endl;
	cout << "Max is: " << max << endl;

	cout << endl << "How to create/change arrays at runtime, dynamic arrays" << endl;
	int size;
	cout << "Size: ";
	cin >> size;
	//int myArray[size]; esto no esta permitido
	int* myArray = new int[size];
	int j = 2;
	for (int i = 0; i < size; i++) {
		myArray[i] = i*j;
		
	}

	for (int i = 0; i < size; i++) {
		cout << *(myArray+i) << " ";
	}
	delete[]myArray;//Le quitamos su ubicacion en memoria
	myArray = NULL;//hacemos que no apunte a ninguna parte

	cout << endl << "What is a dynamic two-dimensional array, multidimensional dynamic arrays" << endl;
	//int rows, cols;
	//cout << "rows, cols: ";
	//cin >> rows >> cols;

	//int** table = new int*[rows];
	//for (int i = 0; i < rows; i++) {
	//	table[i] = new int[cols];
	//}

	////table[1][2] = 88;//warning porque si no se ponen los valores puede fallar
	//for (int i = 0; i < rows; i++) {
	//	delete[]table[i];
	//}
	//delete[]table;
	//table = NULL;


	cout << endl << "How and when to use function pointers" << endl;
	cout << getNumber<<endl; //Si ponemos los parentesis nos dara el valor y si no nos da la dirección de la funcion
	int(*funcPtr)() = getNumber;
	cout << funcPtr() << endl;

	int(*funcPtr2)(int,int) = add;
	cout << funcPtr2(3, 4) << endl;

	vector<int>myNumbers = { 2,5,1,3,6,4 };
	sortAscending(myNumbers);
	printVectorNumbers(myNumbers);
	vector<int>myNumbers2 = { 2,5,1,3,6,4 };
	bool(*funcPtrFuncion)(int, int) = descendingCompare;
	customSort(myNumbers2, funcPtrFuncion);
	printVectorNumbers(myNumbers2);

	cout << endl << "Smart pointers" << endl;
	unique_ptr<int>unPtr1 = make_unique<int>(25); // creacion de un puntero unico, almacenamos la direccion.
	cout << unPtr1 << endl; //en la variable estamo almacenando la direccion del puntero
	cout << *unPtr1 << endl; //con * lo desreferenciamos para obtener el valor que contiene esa dirección

	unique_ptr<int>unPTr2 = move(unPtr1); //ahora es el propietario del puntero unptr1
	cout << *unPTr2 << endl;
	//cout << *unPtr1 << endl; esto causa violacion del segmento al haber movido la direccion de memoria a otro puntero
	cout << endl<< "Creacion de puntero a objeto" << endl;

	{ 
		unique_ptr<MyClass>classPointer = make_unique<MyClass>();
	}

	{
		shared_ptr<MyClass>shPtr1 = make_shared<MyClass>();
		cout << endl << "Shared count: " << shPtr1.use_count() << endl; //use count da el numero de todos los propietarios de ese puntero
		{
			shared_ptr<MyClass>shPtr2 = shPtr1;
			cout << endl << "Shared count: " << shPtr1.use_count() << endl;
		}
		cout << endl << "Shared count: " << shPtr1.use_count() << endl;
	}

	cout << endl << "Creacion de puntero con weak_ptr" << endl;
	//Weak_ptr es un puntero inteligente que contiene una referencia no propietaria, debil, a un objeto administrado por shared_ptr.
	weak_ptr<int>wePtr1;
	{
		shared_ptr<int>shPtr3 = make_shared<int>(25);
		wePtr1 = shPtr3;
	}



	/*Linked list*/
	cout << endl << "Linked list" << endl;
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	head->Value = 1;
	head->Next = second;
	second->Value = 2;
	second->Next = third;
	third->Value = 3;
	third->Next = NULL;
	insertAtTheFront(&head, -1);
	insertAtTheEnd(&head, 4);
	insertAfter(second, 55);
	printList(head);

	
	NodeDoubleLinkedList* headDoubleLinkedList;
	NodeDoubleLinkedList* tailDoubleLinkedList;
	//add first node
	NodeDoubleLinkedList* nodeDoubleLinkedList = new NodeDoubleLinkedList();
	nodeDoubleLinkedList->Value = 4;
	nodeDoubleLinkedList->Next = nullptr;
	nodeDoubleLinkedList->Previous = nullptr;
	headDoubleLinkedList = nodeDoubleLinkedList;
	tailDoubleLinkedList = nodeDoubleLinkedList;
	//add second node u otros elementos, la forma de añadirlos siempre va a ser la misma
	nodeDoubleLinkedList = new NodeDoubleLinkedList();
	nodeDoubleLinkedList->Value=5;
	nodeDoubleLinkedList->Next = nullptr;
	nodeDoubleLinkedList->Previous = tailDoubleLinkedList;
	tailDoubleLinkedList->Next = nodeDoubleLinkedList;
	tailDoubleLinkedList = nodeDoubleLinkedList;

	printForward(headDoubleLinkedList);
	printForward(tailDoubleLinkedList);

	/*Estructura de datos en forma de arboles*/
	cout << endl << "Tree Data Structures" << endl;
	//Level 1
	NodeBinaryTree* root = createNode(1);
	//Level 2
	root->left = createNode(2);
	root->right = createNode(3);
	//Level 3
	root->left->left = createNode(4);
	root->left -> right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	//Level 4
	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);

	printTreePreorden(root);
	printTreeInorden(root);

	/*Breadth first search and deepth first search*/
	cout << endl << "Breadth first search and deepth first search" << endl;
	//Vector de los bordes del grafo. El vertice 0 es un nodo individual
	vector<Edge>edges = { {1,2},{1,3},{1,4},{2,5},{2,6},{5,9},{5,10},{4,7},{4,8},{7,11},{7,12} };
	//Numero total de nodos en el grafo
	int nNodos= 13;
	//se construye el grafo
	Graph graph(edges, nNodos);
	vector<bool>discovered(nNodos, false);
	//Realizar el recorrido BFS desde todos los nodos no descubiertos hasta cubrir todos los componentes conectados de un grafo
	for (int i = 0; i < n; i++) {
		if (discovered[i] == false) {
			//Inicializamos el recorrido BFS desde el nodo i correspondiente
			BFS(graph, i, discovered);
		}
	}

	/*Maps*/
	cout << endl << "Maps" << endl;
	map<string, string>myDictionary;//Siempre inserta los elementos ordenados
	//si usaremos unordored_map<string,string>dictionary insertaria los elementos en el orden en el que se encuentren.
	myDictionary.insert(pair<string, string>("Apple","Manzana"));
	myDictionary.insert(pair<string, string>("Banana", "Platano"));
	myDictionary.insert(pair<string, string>("Orange", "Naranja"));
	myDictionary.insert(pair<string, string>("StrawBerry", "Fresa"));
	
	for (auto pair : myDictionary) {
		cout << pair.first << " - " << pair.second << endl;
	}

	myDictionary["StrawBerry"] = "Frambuesa";//Las claves deben ser unicas pero el valor que contienen puede estar repetido
	int totalElements=myDictionary.size();//Devuelve el numero de elementos
	myDictionary.clear();//Vacia el diccionario

	map<string, list<string>>pokedex;
	list<string>pikachuAttacks{"Thunder shock","tail whip","Thunder","quick attack"};
	list<string>charmanderAttacks{ "flame thrower","scary face", "sun day","dragon dance" };
	list<string>squirtleAttacks{ "surf","rain dance","hydrobomb","ice punch" };
	
	pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
	pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
	pokedex.insert(pair<string, list<string>>("Squirtle", squirtleAttacks));

	for (auto pair : pokedex) {
		cout << pair.first << " - ";
		for (auto attack : pair.second) {
			cout << attack << ", ";
		}
		cout << endl;
	}

	/*Lambda expressions*/
	cout << endl << "Lambda expressions" << endl;

	//struct {
	//	void operator()(int x) {
	//		cout << x << "\n";
	//	}

	//}something;
	
	vector<int>vn{ 2,3,7,14,23 };
	for_each(vn.begin(), vn.end(), [](int x) {cout << x << "\n"; });
	for_each(vn.begin(), vn.end(), [](int x) {
		if (x % 2 == 0)
			cout << x << "numero par"<<endl;
		else {
			cout << x << "Numero impar" << endl;
		}
	});

	int d = 3;//Este valor no puede ser cambiado dentro de la sentencia lambda dado que es el que se usa para realizar la operacion que necesitemos
	for_each(vn.begin(), vn.end(), [d](int x) {
		if (x % d == 0)
			cout << x << "Se puede dividir por "<< d << endl;
		else
			cout << x << "No es divisible por "<<d << endl;

	});

	/*Threads*/
	cout << endl << "Threads" << endl;
	thread worker1(functionThread1,'O');
	thread worker2(functionThread2);

	cout << endl << "Multi Threading" << endl;
	map<string, int>forecastMap = { { "Madrid",13 }, { "Barcelona",20 }, { "Bilbao",10 } };
	thread bgWorker(RefreshForecast, forecastMap);

	/*Operator OverLoading */
	cout << endl << "Operator Overlading" << endl;
	YouTubeChannel yt1 = YouTubeChannel("Hola", 8090);
	YouTubeChannel yt2 = YouTubeChannel("Adios",9090);
	cout << yt1<<yt2; 
	operator<<(cout, yt1);//Es lo mismo que la linea de arriba pero solo nos permite poner uno de las dos estructuras (struct)
	MyCollection myCollection;
	myCollection += yt1;
	myCollection += yt2;
	myCollection -= yt2;
	cout << myCollection;//Provoca fallo si no sobrecargamos el operador
	
	/*STL vector -> Relationship between static array; dynamic array and STL vector*/
	cout << endl << "STL vector -> Relationship between static array; dynamic array and STL vector" << endl; 
	
	vector<int>numbersVector;
	numbersVector.push_back(0);

	for (int i = 1; i <= 10; i++) {
		numbersVector.push_back(i);
	}

	for (auto it = numbersVector.begin(); it != numbersVector.end(); it++) {
		cout << *it << endl;
		cout<< &it << endl;
		cout << &(*it) << endl;
	}

	system("pause>nul");
}