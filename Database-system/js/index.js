$(document).ready(function() {
    var imgs;
    var img_count;
    var img_position = 1;

    imgs = $(".slide ul");
    img_count = imgs.children().length;

$('#back').click(function(){
    back();
});

$('#next').click(function(){
    next();
});

function back() {
    if(1<img_position) {
        imgs.animate({
            left:'+=100%'
        });
        img_position--;
    } else {
        imgs.animate({
            left:'-='+100 * (img_count-1)+'%'
        });
        img_position = img_count;
    }
}

function next() {
    if(img_count > img_position) {
        imgs.animate({
            left:'-=100%'
        });
        img_position++;
        }  else {
            imgs.animate({
                left:'+='+100 * (img_count-1)+'%'
            });
            img_position = 1;
        }
    }
});