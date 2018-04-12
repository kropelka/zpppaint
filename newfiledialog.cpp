#include "newfiledialog.h"
#include<QVBoxLayout>
#include<QFormLayout>
#include<QAction>

NewFileDialog::NewFileDialog()
{
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Szerokość", &imageWidthEdit);
    formLayout->addRow("Wysokość", &imageHeightEdit);
    QWidget *dialogFields = new QWidget;
    dialogFields->setLayout(formLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(dialogFields);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}
