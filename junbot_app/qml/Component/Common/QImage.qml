import QtQuick 2.0

Image
{
    id: root
    property string imgName: CONST.EMPTY_STRING
    source: imgName !== CONST.EMPTY_STRING ? CONST.IMAGE_PREFIX + root.imgName
                                           : CONST.EMPTY_STRING
}
