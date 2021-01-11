struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

int add_node(struct nodeClass* n, int clsid) {
  struct nodeClass* new_node = NULL;
  new_node = (struct nodeClass*)malloc(sizeof(struct nodeClass));
  new_node->classID = clsid;
  n->next = new_node;
}

int checkdigit(int id) {
	int digits;
	int ID = id;
	for (digits = 1; id / 10 != 0; digits++)
	{
		id /= 10;
	}
	int exp;
	for (int i = 0; i < digits; i++)
	{
		exp = ID % 10;
		ID /= 10;
	}
	switch (exp)
	{
	case 6:
		return 1;
		break;
	case 7:
		return 2;
		break;
	case 8:
		return 3;
		break;
	case 9:
		return 4;
		break;
	}

}

void insert(struct nodeClass** head, int id, int midterm) {
	if (*head == NULL)
	{
		struct nodeClass* current;
		struct nodeClass* new_node = (struct nodeClass*) malloc(sizeof(struct nodeClass));
		new_node->classID = 1;
		*head = new_node;
		current = *head;
		for (int i = 2; i < 5; i++)
		{
			add_node(current, i);
			current = current->next;
		}
	}

	struct nodeStudent* newstudent = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	newstudent->midterm = midterm;
	newstudent->studentID = id;

	struct nodeClass* whichcls;
	whichcls = *head;
	for (int i = 1; i < checkdigit(id); i++)
	{
		whichcls = whichcls->next;
	}
	
	struct nodeStudent* currentstudent;

	if (whichcls->studentPtr == NULL || whichcls->studentPtr->midterm <= newstudent->midterm) {
		newstudent->next = whichcls->studentPtr;  
    	whichcls->studentPtr = newstudent; 
    } else 
	{
    	currentstudent = whichcls->studentPtr; 
    	while (currentstudent->next != NULL && currentstudent->next->midterm > newstudent->midterm)
		{ 
    	    currentstudent = currentstudent->next; 
    	} 
    	newstudent->next = currentstudent->next; 
    	currentstudent->next = newstudent; 
    }
	
}

void computeClassAverage(struct nodeClass* head) {
	struct nodeStudent* currentstudent;
	while (head != NULL) {
		double sum = 0;
		int studcounter = 0;
		currentstudent = head->studentPtr;
		while (currentstudent != NULL)
		{
			sum += currentstudent->midterm;
			currentstudent = currentstudent->next;
			studcounter++;
		}
		head->classMidtermAverage = sum / studcounter;
        head = head->next; 
    } 
}

void printAll(struct nodeClass* head) {
	struct nodeStudent* currentstudent;
	while (head != NULL) {
        printf("%d %.2f\n", head->classID, head->classMidtermAverage);
		currentstudent = head->studentPtr;
		while (currentstudent != NULL)
		{
			printf("%d %d\n", currentstudent->studentID, currentstudent->midterm);
			currentstudent = currentstudent->next;
		}
        head = head->next; 
    } 
}


// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



