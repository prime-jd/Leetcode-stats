const express = require('express');
const axios = require('axios');

const app = express();
const PORT = process.env.PORT || 3000;

app.get('/leetcode/:username', async (req, res) => {
    const username = req.params.username;
    const url = `https://alfa-leetcode-api.onrender.com/${username}/solved`;  // Replace with your actual API endpoint

    try {
        // Fetch the LeetCode data
        const response = await axios.get(url);
        const data = response.data;

        const easy = data.easySolved || 0;
        const medium = data.mediumSolved || 0;
        const hard = data.hardSolved || 0;

        // Fetch additional data from the username API
        const userInfoUrl = `https://alfa-leetcode-api.onrender.com/${username}`;
        const userInfoResponse = await axios.get(userInfoUrl);
        const userInfo = userInfoResponse.data;

        const userDisplayName = userInfo.username || username;

        const svg = `
        <svg viewBox="0 0 400 250" xmlns="http://www.w3.org/2000/svg">
            <!-- Gradient Background -->
            <defs>
                <linearGradient id="grad1" x1="0%" y1="0%" x2="100%" y2="100%">
                    <stop offset="0%" style="stop-color:#4A00E0;stop-opacity:1" />
                    <stop offset="100%" style="stop-color:#8E2DE2;stop-opacity:1" />
                </linearGradient>
                <filter id="f1" x="0" y="0">
                    <feOffset result="offOut" in="SourceAlpha" dx="5" dy="5" />
                    <feGaussianBlur result="blurOut" in="offOut" stdDeviation="3" />
                    <feBlend in="SourceGraphic" in2="blurOut" mode="normal" />
                </filter>
            </defs>

            <!-- Background -->
            <rect width="100%" height="100%" fill="url(#grad1)" rx="20" ry="20" />

            <!-- Username -->
            <text x="50%" y="50" font-size="28" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif" font-weight="bold">
                ${userDisplayName}'s LeetCode Stats
            </text>

            <!-- Text -->
            <text x="50%" y="110" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif">
                Easy: ${easy}
            </text>
            <text x="50%" y="140" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif">
                Medium: ${medium}
            </text>
            <text x="50%" y="170" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif">
                Hard: ${hard}
            </text>

            <!-- 3D Effect on Text -->
            <text x="50%" y="110" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif" filter="url(#f1)">
                Easy: ${easy}
            </text>
            <text x="50%" y="140" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif" filter="url(#f1)">
                Medium: ${medium}
            </text>
            <text x="50%" y="170" font-size="22" fill="#ffffff" text-anchor="middle" font-family="'Segoe UI', Tahoma, Geneva, Verdana, sans-serif" filter="url(#f1)">
                Hard: ${hard}
            </text>

            <!-- Additional Style: Glow Effect -->
            <style>
                text {
                    text-shadow: 0 0 6px rgba(255, 255, 255, 0.6);
                }
            </style>
        </svg>`;

        res.setHeader('Content-Type', 'image/svg+xml');
        res.send(svg);
    } catch (error) {
        res.status(500).send(`Error fetching data for ${username}: ${error.message}`);
    }
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
