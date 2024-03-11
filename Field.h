#pragma once

class Field
{
public:
    Field();
    ~Field();

    void Show() const;

private:
    char** field;

    // Dimensions
    const int ROWS;
    const int COLUMNS;

    // Helper functions
    void Clear();
    void InitRows();
    void InitColumns();
};



