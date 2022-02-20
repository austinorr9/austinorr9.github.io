/* -----------------------------------------------------------------------------

FILE NAME:         main.cpp

DESCRIPTION:       Main file for milestone one

PURPOSE:           contains enchancements of files for project one

USAGE:             make using first example below, then run using second example

EXAMPLES:          make (FILE NAME), ./(FILE NAME)

PARAMETERS:        none

EXIT CODES:        0 = Success
				   Otherwise = Error

COMPILATION:       gnu g++

NOTES:             Known bug program crashes if ID number when displaying information dosent exist

MODIFICATION HISTORY:

Author          Date			Modification(s)
-------------   -----------		---------------
Austin Orr      01-23-2022		Start programing
Austin Orr      02-20-2022		Added: 
								Delete info function.
								Dummy values
								Changed: 
								Updated how the info was being handled,
								Optimized all functions.

----------------------------------------------------------------------------- */
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

//Structure for appoitnment info
struct AppointmentInfo {
	int id;
	std::string date;
	std::string description;

};

//Structure for Contact Info
struct ContactInfo {
	int id;
	std::string firstName;
	std::string lastName;
	std::string phone;
	std::string address;
};

//Structure for Task Info
struct TaskInfo {
	int id;
	std::string name;
	std::string description;
};

//Gloal vairables
int choice;
bool flag;
int local;
int idTemp;
std::string temp;
std::vector<AppointmentInfo> appointment;
std::vector<ContactInfo> contact;
std::vector<TaskInfo> task;
AppointmentInfo appoint;
ContactInfo con;
TaskInfo ta;

//Functions
void menu();
void constructor();
void appointmentService();
void contactService();
void taskService();
void addInfo();
void updateInfo();
void displayInfo();
void deleteInfo();


/*
* Main function
*/
int main(int argc, char* argv[]) {

	//Calls constructor 
	constructor();

	//Calls menu fucntion
	menu();

	return 0;
}

/*
* Constructor for some of the global values
*/
void constructor() {
	//Initilize global variables
	choice = 0;
	flag = false;
	local = 0;
	temp = "";
	idTemp = NULL;

	//Initilize appointment structure
	appointment.push_back(appoint);
	appointment[0].id = 0;
	appointment[0].date = "2022-02-20";
	appointment[0].description = "Rash";

	//Initilize contact structure
	contact.push_back(con);
	contact[0].id = 0;
	contact[0].firstName = "John";
	contact[0].lastName = "Smith";
	contact[0].phone = "1234567890";
	contact[0].address = "123 Some Road Town,State 12345";

	//Initilize task structure
	task.push_back(ta);
	task[0].id = 0;
	task[0].name = "ToDo";
	task[0].description = "Get to work!";
}


/*
* Handles the appointment menu
*/
void appointmentService() {

	local = 1;

	while (flag != true) {

			std::cout << "Please select option" << std::endl
					<< "1. Create New Appointment" << std::endl
					<< "2. Display Appointment" << std::endl
					<< "3. Update Appointment" << std::endl
					<< "4. Remove Appointment" << std::endl
					<< "5. Back" << std::endl
					<< "Enter choice: ";

				std::cin >> choice;

		switch (choice) {
		case 1: {
			addInfo();
			//std::cout << "addInfo()" << std::endl;
			break;
		}
		case 2: {
			displayInfo();
			//std::cout << "displayInfo()" << std::endl;
			break;
		}
		case 3: {
			updateInfo();
			//std::cout << "updateInfo()" << std::endl;
			break;
		}
		case 4: {
			deleteInfo();
			//std::cout << "deleteInfo()" << std::endl;
			break;
		}
		case 5: {
			local = 0;
			menu();
			break;
		}
		default: {
			std::cout << "Invalid selection, please try again" << std::endl;
			break;
		}
		}
	}

}

/*
* Handles the Contact menu
*/
void contactService() {
	local = 2;

	while(flag != true){

		std::cout << "Please select option" << std::endl
			<< "1. Create New Contact" << std::endl
			<< "2. Display Contact Info" << std::endl
			<< "3. Remove Contact" << std::endl
			<< "4. Update Contact Info" << std::endl
			<< "5. Back" << std::endl
			<< "Enter choice: ";

		std::cin >> choice;
		switch (choice) {
		case 1: {
			addInfo();
			//std::cout << "addInfo()" << std::endl;
			break;
		}
		case 2: {
			displayInfo();
			//std::cout << "displayInfo()" << std::endl;
			break;
		}
		case 3: {
			deleteInfo();
			//std::cout << "deleteInfo()" << std::endl;
			break;
		}
		case 4: {
			updateInfo();
			//std::cout << "updateInfo()" << std::endl;
			break;
		}
		case 5: {
			local = 0;
			menu();
			break;
		}
		default: {
			std::cout << "Invalid selection, please try again" << std::endl;
			break;
		}
		}
	}


}


/*
* Handles the task menu
*/
void taskService() {

	//Sets local value to 3
	local = 3;

	while (flag != true) {
		//menu for task
		std::cout << "Please select option" << std::endl
			<< "1. Create New Task" << std::endl
			<< "2. Display Task Info" << std::endl
			<< "3. Remove Task" << std::endl
			<< "4. Update Task Info" << std::endl
			<< "5. Back" << std::endl
			<< "Enter choice: ";

		std::cin >> choice;

		//Calls specific functions 
		switch (choice) {
		case 1: {
			addInfo();
			//std::cout << "addInfo()" << std::endl;
			break;
		}
		case 2: {
			displayInfo();
			//std::cout << "displayInfo()" << std::endl;
			break;
		}
		case 3: {
			deleteInfo();
			//std::cout << "deleteInfo()" << std::endl;
			break;
		}
		case 4: {
			updateInfo();
			//std::cout << "updateInfo()" << std::endl;
			break;
		}
		case 5: {
			local = 0;
			menu();
			break;
		}
		default: {
			std::cout << "Invalid selection, please try again" << std::endl;
			break;
		}
		}
	}
}

/*
* Adds new info
*/
void addInfo() {

	//based on local value will add info to appropriate structure
	switch (local) {

	//Add info to appointment structure
	case 1: {
		std::cout << std::endl;

		appointment.push_back(appoint);

		idTemp = appointment.size() - 1;
		appointment[idTemp].id = idTemp;

		std::cout << "Enter Date (YYYY-MM-DD): ";
		std::cin >> temp;

		if (temp == "") {
			std::cout << "invalid" << std::endl;
		}
		else {
			appointment[idTemp].date = temp;
		}

		std::cout << "Enter Description of visit: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 50) {
			std::cout << "invalid" << std::endl;
		}
		else {
			appointment[idTemp].description = temp;
		}


		break;
	}

	//Add info to contact structure
	case 2: {
		std::cout << std::endl;

		contact.push_back(con);
		idTemp = contact.size() - 1;
		contact[idTemp].id = idTemp;

		std::cout << " Enter First Name: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 10) {
			std::cout << "invalid" << std::endl;
		}
		else {
			contact[idTemp].firstName = temp;
		}

		std::cout << std::endl << "Enter Last Name: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 10) {
			std::cout << "invalid" << std::endl;
		}
		else {
			contact[idTemp].lastName = temp;
		}

		std::cout << std::endl << "Enter phone: ";
		std::cin >> temp;

		if (temp == "" || temp.length() != 10) {
			std::cout << "invalid" << std::endl;
		}
		else {
			contact[idTemp].phone = temp;
		}

		std::cout << std::endl << "Enter address: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 30) {
			std::cout << "invalid" << std::endl;
		}
		else {
			contact[idTemp].address = temp;
		}

		std::cout << std::endl;

		break;
	}

	//Add info to task structure
	case 3: {
		std::cout << std::endl;

		task.push_back(ta);
		idTemp = task.size() - 1;
		task[idTemp].id = idTemp;

		std::cout << " Enter name of task: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 20) {
			std::cout << "invalid" << std::endl;
		}
		else {
			task[idTemp].name = temp;
		}

		std::cout << std::endl << "Enter description of task: ";
		std::cin >> temp;

		if (temp == "" || temp.length() > 50) {
			std::cout << "invalid" << std::endl;
		}
		else {
			task[idTemp].description = temp;
		}

		std::cout << std::endl;

		break;
	}
	}

}


/*
* Updates info based on ID number
*/
void updateInfo() {

	
	//based on local value will updat info to appropriate structure
	switch (local) {

	//Update info for appointment structure
	case 1: {
		std::cout << "Enter ID: ";

		std::cin >> idTemp;

		for (int i = 0; i <= appointment.size(); i++) {
			if (idTemp == appointment[i].id) {
				std::cout << " Enter Date (YYYY-MM-DD): ";
				std::cin >> temp;

				if (temp == "") {
					std::cout << "invalid" << std::endl;
				}
				else {
					appointment[i].date = temp;
				}

				std::cout << std::endl << "Enter Description of visit: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 50) {
					std::cout << "invalid" << std::endl;
				}
				else {
					appointment[i].description = temp;
				}
				break;
			}
		}
		std::cout << std::endl;

		break;
		
	}

	//Update info for contact structure
	case 2: {
		std::cout << " Enter contact ID: ";
		std::cin >> idTemp;

		for (int i = 0; i <= contact.size(); i++) {
		
			if (idTemp == contact[i].id) {
				std::cout << " Enter First Name: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 10) {
					std::cout << "invalid" << std::endl;
				}
				else {
					contact[i].firstName = temp;
				}

				std::cout << std::endl << "Enter Last Name: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 10) {
					std::cout << "invalid" << std::endl;
				}
				else {
					contact[i].lastName = temp;
				}

				std::cout << std::endl << "Enter phone: ";
				std::cin >> temp;

				if (temp == "" || temp.length() != 10) {
					std::cout << "invalid" << std::endl;
				}
				else {
					contact[i].phone = temp;
				}

				std::cout << std::endl << "Enter address: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 30) {
					std::cout << "invalid" << std::endl;
				}
				else {
					contact[i].address = temp;
				}
				break;
			}
		}

		std::cout << std::endl;
		break;
	}

	//Update info for task structure
	case 3: {
		std::cout << " Enter task id: ";
		std::cin >> idTemp;

		for (int i = 0; i <= task.size(); i++) {
			if (idTemp == task[i].id) {
				std::cout << " Enter name of task: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 20) {
					std::cout << "invalid" << std::endl;
				}
				else {
					task[i].name = temp;
				}

				std::cout << std::endl << "Enter description of task: ";
				std::cin >> temp;

				if (temp == "" || temp.length() > 50) {
					std::cout << "invalid" << std::endl;
				}
				else {
					task[i].description = temp;
				}
				break;
			}
		}

		std::cout << std::endl;
		break;
	}


	}
}


/*
* Deletes info from appropriate structure based on ID number
*/
void deleteInfo() {
	//based on local value will display info to appropriate structure
	switch (local) {

	//Deletes info from appointment structure
	case 1: {

		std::cout << "Enter ID: " << std::endl;

		std::cin >> idTemp;

		for (int i = 0; i <= appointment.size(); i++) {
			if (idTemp == appointment[i].id) {
				appointment.erase(appointment.begin() + i);
				break;

			}
		}
		std::cout << std::endl;
		break;
	}

	//Deletes info from contact structure
	case 2: {
		std::cout << "Enter ID: ";

		std::cin >> idTemp;
		std::cout << std::endl;

		for (int i = 0; i <= contact.size(); i++) {
			if (contact[i].id == idTemp) {
				contact.erase(contact.begin() + i);
				break;
			}

		}
		std::cout << std::endl;
		break;
	}

	//Deletes info from task structures
	case 3: {
		std::cout << "Enter ID: ";

		std::cin >> idTemp;
		std::cout << std::endl;

		for (int i = 0; i <= task.size(); i++) {
			if (task[i].id == idTemp) {
				task.erase(task.begin() + i);
				break;
			}

		}
		std::cout << std::endl;
		break;
	}
	}
}


/*
* Displays info appropriate info based on ID number
*/
void displayInfo() {

	//based on local value will display info to appropriate structure
	switch (local) {

	//Dispplays info from appointment structure
	case 1: {

		std::cout << "Enter ID: " << std:: endl;

		std::cin >> idTemp;

		std::cout << std::endl << "Appointment Info" << std::endl;


		for (int i = 0; i <= appointment.size(); i++) {
			if (idTemp == appointment[i].id) {
				std::cout << "ID: " << appointment[i].id << std::endl
					<< "Date: " << appointment[i].date << std::endl
					<< "Descritption: " << appointment[i].description << std::endl;
				break;
			}
		}

		std::cout << std::endl;
		break;
	}

	//Displays info from contact structure
	case 2: {
		std::cout << "Enter ID: ";

		std::cin >> idTemp;
		std::cout << std::endl;

		for (int i = 0; i <= contact.size(); i++) {
			if (contact[i].id == idTemp) {
				std::cout << "ID: " << contact[i].id << std::endl
					<< "First Name: " << contact[i].firstName << std::endl
					<< "Last Name: " << contact[i].lastName << std::endl
					<< "Phone Number: " << contact[i].phone << std::endl
					<< "Address: " << contact[i].address << std::endl;
				break;
			}

		}
		std::cout << std::endl;
		break;
	}

	//Displays info from task structure
	case 3: {
		std::cout << "Enter ID: ";

		std::cin >> idTemp;
		std::cout << std::endl;

		for (int i = 0; i <= task.size(); i++) {
			if (task[i].id == idTemp) {
				std::cout << "ID: " << task[i].id << std::endl
					<< "Task Name: " << task[i].name << std::endl
					<< "Description: " << task[i].description << std::endl;
				break;
			}

		}
		std::cout << std::endl;
		break;
	}
	}
}

/*
* Handles main menu screen
*/
void menu() {

	//While loop keeps menu on screen until condition is met
	while (flag != true) {

		//Main menu
		std::cout << "Please Select option" << std::endl
			<< "1. Apppointment info" << std::endl
			<< "2. Contact info" << std::endl
			<< "3. Task info" << std::endl
			<< "4. Exit" << std::endl
			<< "Enter your choice: ";

		//Users input
		std::cin >> choice;

		//Switch loop based on users input
		switch (choice) {

		case 1: {
			appointmentService();
			break;
		}
		case 2: {
			contactService();
			break;
		}
		case 3: {
			taskService();
			flag = true;
			break;
		}
		case 4: {
			std::cout << "Have a nice day :)" << std::endl;
			flag = true;
			break;
		}
		default: {
			std::cout << "Invalid selection, please try again" << std::endl;
			break;
		}
		}

	};
}

