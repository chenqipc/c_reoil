#include <opencv2/opencv.hpp>
#include <unordered_map>
#include <string>

cv::Rect FirstGun(1760, 115, 660, 260);
cv::Rect SecondGun(1760, 388, 660, 260);

std::unordered_map<std::string, cv::Rect> Attachments = {
        {"Muzzle", cv::Rect(12, 187, 66, 66)},
        {"Grip",   cv::Rect(148, 187, 67, 66)},
        {"Sight",  cv::Rect(375, 38, 67, 61)}
};

cv::Rect WeaponName(62, 10, 238, 45);
cv::Rect Inventory(490, 73, 205, 45);
cv::Rect Bullets(1250, 1315, 58, 50);
cv::Rect Stand(930, 1299, 65, 71);