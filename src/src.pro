QT += core gui
QT += core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libs/RangeLineEdit/DoubleLineEdit.cpp \
    libs/RangeLineEdit/LatitudeLineEdit.cpp \
    libs/RangeLineEdit/LongitudeLineEdit.cpp \
    libs/RangeLineEdit/PhoneNumberLineEdit.cpp \
    libs/RangeLineEdit/PositionalLineEdit.cpp \
    libs/RangeLineEdit/Ranges.cpp \
    libs/RangeLineEdit/TrianglePaintedButton.cpp \
    logics/order.cpp \
    logics/products/car.cpp \
    logics/products/detail.cpp \
    logics/products/product.cpp \
    logics/user.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/buttons/customcheckbox.cpp \
    widgets/buttons/menubutton.cpp \
    widgets/buttons/profileLineEdits/profilelineedit_int.cpp \
    widgets/buttons/profileLineEdits/profilelineedit_phone.cpp \
    widgets/buttons/profileLineEdits/profilelineedit_string.cpp \
    widgets/infowidget.cpp \
    widgets/layouts/layoutcombobox.cpp \
    widgets/layouts/layoutdoublespinbox.cpp \
    widgets/layouts/layoutlineedit.cpp \
    widgets/layouts/layoutspinbox.cpp \
    widgets/line.cpp \
    widgets/mainwidget.cpp \
    widgets/menu.cpp \
    widgets/menuWidgets/cartwidget.cpp \
    widgets/menuWidgets/catalogwidget.cpp \
    widgets/menuWidgets/productinfowidget.cpp \
    widgets/menuWidgets/profilewidget.cpp \
    widgets/menuWidgets/userorderswidget.cpp \
    widgets/menuWidgets/userproductswidget.cpp \
    widgets/modalWindows/addcarwindow.cpp \
    widgets/modalWindows/adddetailwindow.cpp \
    widgets/modalWindows/addproductwindow.cpp \
    widgets/modalWindows/buyproductwindow.cpp \
    widgets/signinform.cpp \
    widgets/signupform.cpp \
    widgets/welcomewidget.cpp

HEADERS += \
    libs/RangeLineEdit/DoubleLineEdit.h \
    libs/RangeLineEdit/LatitudeLineEdit.h \
    libs/RangeLineEdit/LongitudeLineEdit.h \
    libs/RangeLineEdit/PhoneNumberLineEdit.h \
    libs/RangeLineEdit/PositionalLineEdit.h \
    libs/RangeLineEdit/RangeLineEdit.h \
    libs/RangeLineEdit/Ranges.h \
    libs/RangeLineEdit/TrianglePaintedButton.h \
    logics/order.h \
    logics/products/car.h \
    logics/products/detail.h \
    logics/products/product.h \
    logics/user.h \
    mainwindow.h \
    widgets/buttons/customcheckbox.h \
    widgets/buttons/menubutton.h \
    widgets/buttons/profileLineEdits/profilelineedit_int.h \
    widgets/buttons/profileLineEdits/profilelineedit_phone.h \
    widgets/buttons/profileLineEdits/profilelineedit_string.h \
    widgets/infowidget.h \
    widgets/layouts/layoutcombobox.h \
    widgets/layouts/layoutdoublespinbox.h \
    widgets/layouts/layoutlineedit.h \
    widgets/layouts/layoutspinbox.h \
    widgets/line.h \
    widgets/mainwidget.h \
    widgets/menu.h \
    widgets/menuWidgets/cartwidget.h \
    widgets/menuWidgets/catalogwidget.h \
    widgets/menuWidgets/productinfowidget.h \
    widgets/menuWidgets/profilewidget.h \
    widgets/menuWidgets/userorderswidget.h \
    widgets/menuWidgets/userproductswidget.h \
    widgets/modalWindows/addcarwindow.h \
    widgets/modalWindows/adddetailwindow.h \
    widgets/modalWindows/addproductwindow.h \
    widgets/modalWindows/buyproductwindow.h \
    widgets/signinform.h \
    widgets/signupform.h \
    widgets/welcomewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    json/orders.json \
    json/products.json \
    json/users.json \
    libs/RangeLineEdit/.gitignore \
    libs/RangeLineEdit/LICENSE \
    libs/RangeLineEdit/README.md

RESOURCES += \
    resources.qrc

SUBDIRS += \
    libs/RangeLineEdit/RangeLineEdit.pro
