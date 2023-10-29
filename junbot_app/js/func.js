function darker(color, percent) {
    var colorRegex = /^#[0-9A-Fa-f]{6}$/;
    if (!colorRegex.test(color)
            || darker < 0
            || darker > 100) {
        return "#000000";
    }

    var r = parseInt(color.slice(1, 3), 16);
    var g = parseInt(color.slice(3, 5), 16);
    var b = parseInt(color.slice(5, 7), 16);

    r = Math.max(0, r - (r * percent / 100));
    g = Math.max(0, g - (g * percent / 100));
    b = Math.max(0, b - (b * percent / 100));

    var darkerColor = "#" +
        ("00" + Math.round(r).toString(16)).slice(-2) +
        ("00" + Math.round(g).toString(16)).slice(-2) +
        ("00" + Math.round(b).toString(16)).slice(-2);

    return darkerColor;
}

function brighter(color, percent) {
    var colorRegex = /^#[0-9A-Fa-f]{6}$/;

    if (!colorRegex.test(color)
            || percent < 0
            || percent > 100) {
        return "#ffffff";
    }

    var r = parseInt(color.slice(1, 3), 16);
    var g = parseInt(color.slice(3, 5), 16);
    var b = parseInt(color.slice(5, 7), 16);

    r = Math.min(255, r + (255 - r) * percent / 100);
    g = Math.min(255, g + (255 - g) * percent / 100);
    b = Math.min(255, b + (255 - b) * percent / 100);

    var brighterColor = "#" +
        ("00" + Math.round(r).toString(16)).slice(-2) +
        ("00" + Math.round(g).toString(16)).slice(-2) +
        ("00" + Math.round(b).toString(16)).slice(-2);

    return brighterColor;
}
