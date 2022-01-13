# LC350. 两个数组的交集 II

**\*\*Easy\*\***

给定两个数组，编写一个函数来计算它们的交集

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
```

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
```

## 使用map

使用 `std::map` 记录两个数组中每一个元素出现的次数，之后通过查找两个 `map` 中共同含有的元素，取得出现次数较小的那个并放入 `std::vector` 中

```C++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return ans;
        }

        // Use to map to store apparence
        std::map<int, int> map1;
        std::map<int, int> map2;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (std::find(nums1.begin(), nums1.end(), nums1[i]) == nums1.end())
            {
                map1.insert(pair<int, int>(nums1[i], 0));
            }
            map1[nums1[i]]++;
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            if (std::find(nums2.begin(), nums2.end(), nums2[j]) == nums2.end())
            {
                map2.insert(pair<int, int>(nums2[j], 0));
            }
            map2[nums2[j]]++;
        }

        // Now check if there is a intersection between two maps
        for (auto iter = map1.begin(); iter != map1.end(); iter++)
        {
            if (map2.find(iter->first) != map2.end())
            {
                // Get it
                int num = std::min(map1[iter->first], map2[iter->first]);
                while(num > 0)
                {
                    ans.push_back(iter->first);
                    num--;
                }
            }
        }
        
        return ans;
    }
};
```



 ## 使用顺序数组和双指针

首先将两个数组排序

并用双指针同时遍历两个数组

当两个数组的元素相同时将其添加进 `std::vector` 中

当不同时将较小的下标增加



```C++ 
vector<int> ans;

std::sort(nums1.begin(), nums1.end());
std::sort(nums2.begin(), nums2.end());

int idx1 = 0;
int idx2 = 0;

while(idx1 < nums1.size() && idx2 < nums2.size())	// 当其中一个数组遍历完后意味着不会再有相同的元素出现在两个数组当中
{
    if (nums1[idx1] > nums2[idx2])
    {
        idx2++;
    }
    else if (nums1[idx1] < nums2[idx2])
    {
        idx1++;
    }
    else
    {
        ans.push_back(nums1[idx1]);
        idx1++;
        idx2++;
    }
}

return ans;
```

