#pragma once
#include "MyForm1.h"
namespace EDPractiseForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::TextBox^ Password;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::GhostWhite;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(233, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(249, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Azure;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(228, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"АВТОРИЗАЦИЯ ПОЛЬЗОВАТЕЛЯ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Azure;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(59, 236);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Пароль";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Azure;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(59, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 29);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Имя пользователя";
			// 
			// Username
			// 
			this->Username->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Username->BackColor = System::Drawing::Color::GhostWhite;
			this->Username->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Username->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Username->ForeColor = System::Drawing::Color::DarkBlue;
			this->Username->Location = System::Drawing::Point(353, 144);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(305, 33);
			this->Username->TabIndex = 4;
			// 
			// Password
			// 
			this->Password->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Password->BackColor = System::Drawing::Color::GhostWhite;
			this->Password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Password->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 16));
			this->Password->ForeColor = System::Drawing::Color::DarkBlue;
			this->Password->Location = System::Drawing::Point(353, 237);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(305, 33);
			this->Password->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(713, 434);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	bool PasswordTrue(String^ user, String^ password)
		{
			if (user == "Stardurost" && password == "1234") { return true; }
			else
			{
				MessageBox::Show("Вы неверно ввели имя пользователя или пароль !", "Неверные данные", MessageBoxButtons::OK,
					MessageBoxIcon::Exclamation);
				return false;
			}
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ login = Username -> Text;
		String^ pass = Password -> Text;
			if (PasswordTrue(login, pass))
			{
				
				MyForm1^ MainF = gcnew MyForm1;
				MainF->Show();
				MyForm::Hide();
			}

	
	}
	};
}
