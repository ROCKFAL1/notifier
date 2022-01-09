# Notifier - cross-platform library for calling notifications
Notifier is library written in C++17 and providing user-friendly interfaces

# Download & usage
1) `$ git clone https://github.com/ROCKFAL1/notifier.git` then copy paths to `/notifier` folder.  
2) Add `add_subdirectory(<here is path to /notifier folder> ${CMAKE_CURRENT_SOURCE_DIR}/notifier_lib_build EXCLUDE_FROM_ALL)` to your CMake project.
3) Add `target_link_libraries(<project name> PRIVATE notifier)` to your CMake project.
4) Everything is ready!

# Dependencies

| OS  | Libraries  | 
| :-----: |:------:| 
| Windows | WinApi | 
| Linux | libnotify | 

# Documentation
Here is [example](https://github.com/ROCKFAL1/notifier/tree/main/example)  
At first, you need to get the Notif object. This is done using NotifBuilder.
```cpp
//example

notifier::NotifBuilder builder;
auto notif = builder.SetBody("Body").SetHeader("Header").Build();

//or

builder.SetHeader("Header");
builder.SetBody("Body");
auto notif = builder.Build();

```
Next, you can trigger the notification in two different ways
```cpp
//first way
notif->Invoke(); //This will trigger the notification instantly

//second way
auto defferedNotif = notif->InvokeDeffered(/*Some std::chrono::duration argument */); //This will trigger a notification after the specified time
```

In the second case, you can call any of these methods   
```cpp
        void DefferedNotif::Await(); //Suspend execution of the main thread until the notification is called
        void DefferedNotif::Cancel(); //Cancels the notification call
        seconds_t DefferedNotif::RemainingTimeToInvoke() const; //Returns the remaining time before the call
```

# Todo
1) System icons near notifications :white_check_mark: 
2) Custom icons near notification

