#pragma once
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <chrono>
#include <Windows.h>
#include "MyFunctions.h"
#include <thread>
#include <cstdio>
#include <stdio.h>

namespace EDPractiseForms {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			DateTime datetime = DateTime::Now;
			this->label2->Text = "Дата: " + datetime.ToString();
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;


	private: Thread^ Thread1;			// создание потоков
	private: Thread^ Thread2;			// создание потоков
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;



	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 580);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выполнила: Рощупкина Д.В.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(26, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Дата:";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->BackColor = System::Drawing::Color::GhostWhite;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(423, 443);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(312, 68);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Заменить все цифры 6 на @ и изменить расширение файла на .csv";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(31, 134);
			this->textBox1->MaximumSize = System::Drawing::Size(780, 320);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(510, 288);
			this->textBox1->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->BackColor = System::Drawing::Color::GhostWhite;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(423, 517);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(312, 45);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Вывести преобразованный файл";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(93, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Данные из файла";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(622, 134);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(516, 288);
			this->textBox2->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(895, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(194, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Преобразованные данные";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm1::label4_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::Azure;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1041, 578);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 32);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Закрыть";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click_1);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button4->BackColor = System::Drawing::Color::GhostWhite;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(423, 51);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(312, 45);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Загрузить данные из файла";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(1168, 616);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Основное окно";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


	public:	void ThreadA() {
		vector <char> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
		vector <char> vec[10] = { v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 };
		char StringA;

		ifstream file;
		file.open("data.txt");
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				file >> StringA;
				vec[i].push_back(StringA);
				sort(vec[i].begin(), vec[i].end());
				replace(vec[i].begin(), vec[i].end(), '6', '@');
				OutPut(vec[i]);
				vec[i].clear();
			}
			Separe();
		}
		file.close();
	}

	public:	void ThreadB() {
		vector <char> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
		vector <char> vec[10] = { v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 };
		char  StringB;

		ifstream file;

		file.open("data.txt");
		for (int j = 5; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				file >> StringB;
				vec[i].push_back(StringB);
				sort(vec[i].begin(), vec[i].end());
				replace(vec[i].begin(), vec[i].end(), '9', '*');
				OutPut(vec[i]);
				vec[i].clear();
			}
			Separe();
		}
		file.close();
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ NameOfFile = "output.csv";
		StreamReader^ file = File::OpenText(NameOfFile);
		textBox2->Text = file->ReadToEnd();
		file->Close();
		remove("output.csv");
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Thread1 = gcnew Thread(gcnew ThreadStart(this, &MyForm1::ThreadA));
		Thread2 = gcnew Thread(gcnew ThreadStart(this, &MyForm1::ThreadB));
		Thread1->Start();
		Thread1->Join();
		Thread2->Start();
		Thread2->Join();
		MessageBox::Show("Файл был создан !", "Успешно", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

	}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();

	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ Filename = "data.txt";
		StreamReader^ file = File::OpenText(Filename);
		textBox1->Text = file->ReadToEnd();
		file->Close();
	}
	};
}