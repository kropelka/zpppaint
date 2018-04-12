#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include<QDialog>
#include<QDialogButtonBox>
#include<QLineEdit>

class NewFileDialog : public QDialog
{
    Q_OBJECT
public:
    NewFileDialog();

private:
    QDialogButtonBox *buttonBox;
    QLineEdit imageWidthEdit, imageHeightEdit;

private slots:
};

#endif // NEWFILEDIALOG_H
